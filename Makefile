# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 13:43:08 by orantane          #+#    #+#              #
#    Updated: 2020/12/01 15:36:09 by orantane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_NAME = corewar
ASM_NAME = asm

LEXER_TEST_NAME = lexer-test
# FLAGS = -Wall -Werror -Wextra
VM_MAIN = srcs/vm/main.c
ASM_MAIN = srcs/asm/main.c

SRCS = 	srcs/file/file.c srcs/file/read.c srcs/file/write.c \
		srcs/lexer/lexer.c srcs/token/token.c \
		srcs/error.c \
		srcs/encoder/encoder_body/get_argument_type.c srcs/encoder/encoder_body/get_arguments.c srcs/encoder/encoder_body/write_component_size.c \
		srcs/encoder/encoder_body/encoder.c \
		srcs/encoder/encoder_body/get_statement.c srcs/encoder/encoder_body/track_jmps.c srcs/encoder/encoder_body/get_t_dir_special_arguments.c \
		srcs/vm/args.c srcs/vm/read_files.c srcs/vm/arena.c srcs/vm/initiate_carriage.c srcs/vm/decrypt.c srcs/vm/player.c \
		srcs/vm/funcs/helper_functions/get_arg_value.c srcs/vm/funcs/helper_functions/write_bytes.c srcs/vm/funcs/helper_functions/read_bytes.c\
		srcs/vm/funcs/helper_functions/copy_carriage.c srcs/vm/memspace.c srcs/vm/statement.c srcs/vm/statement_args.c \
		srcs/vm/funcs/live.c srcs/vm/funcs/ld.c  srcs/vm/funcs/st.c  srcs/vm/funcs/add.c \
		srcs/vm/funcs/sub.c srcs/vm/funcs/and.c  srcs/vm/funcs/or.c  srcs/vm/funcs/xor.c \
		srcs/vm/funcs/zjmp.c srcs/vm/funcs/ldi.c  srcs/vm/funcs/sti.c  srcs/vm/funcs/fork.c \
		srcs/vm/funcs/lld.c srcs/vm/funcs/lldi.c  srcs/vm/funcs/lfork.c  srcs/vm/funcs/aff.c \
		srcs/ast/ast.c srcs/ast/compound_insert.c srcs/ast/encode_statement.c srcs/ast/init_ast.c srcs/ast/visit_body.c srcs/ast/visit_compound.c \
		srcs/ast/visit_header.c  srcs/ast/visit_instruction.c \
		srcs/ast/assign_data_to_struct.c \
		srcs/parser/parser.c srcs/parser/parser_header.c \
		srcs/parser/parser_body.c srcs/parser/parser_args.c \
		srcs/parser/parser_error.c \
		srcs/opcode/opcode.c \
		srcs/label/label.c \
		srcs/encoder/encoder_header/encoder.c \
		srcs/vm/battle_loop.c \
		srcs/vm/carriage_check.c \

INCL = ./includes
LIBFT = ./libft
LIBFTINCL = $(LIBFT)/includes

all: $(VM_NAME) $(ASM_NAME)

$(VM_NAME): $(SRCS) $(INCL) $(VM_MAIN)
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init; \
	fi
	make -C $(LIBFT)
	gcc -o $(VM_NAME) $(VM_MAIN) -I$(INCL) $(SRCS)  \
	-L$(LIBFT) -lft -I$(LIBFTINCL)

$(ASM_NAME): $(SRCS) $(INCL) $(ASM_MAIN)
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init; \
	fi
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(ASM_NAME) $(ASM_MAIN) $(SRCS) -I$(INCL) \
	-L$(LIBFT) -lft -I$(LIBFTINCL)

clean:
	make clean -C $(LIBFT)

fclean:
	make fclean -C $(LIBFT)
	rm -f $(VM_NAME)
	rm -f $(ASM_NAME)
	rm -f $(LEXER_TEST_NAME)
	rm -f file-test
	rm -f encoder-test
	rm -f hash-test

re: fclean all

lexer-test: $(SRCS) $(INCL) srcs/lexer/lexer_test/lexer_test.c
	make -C $(LIBFT)
	gcc -o $(LEXER_TEST_NAME) srcs/lexer/lexer_test/lexer_test.c $(SRCS) -I$(INCL) -L$(LIBFT) -lft -I$(LIBFTINCL)

file-test: $(SRCS) $(INCL) srcs/file/file_test/file_test.c
	make -C $(LIBFT)
	gcc -o file-test srcs/file/file_test/file_test.c $(SRCS) -I$(INCL) -L$(LIBFT) -lft -I$(LIBFTINCL)

encoder-test: $(SRCS) $(INCL) srcs/encoder/encoder_body/encoder_test/encoder_body_test_main.c
	make -C $(LIBFT)
	gcc -o encoder-test srcs/encoder/encoder_body/encoder_test/encoder_body_test_main.c $(SRCS) -I$(INCL) -L$(LIBFT) -lft -I$(LIBFTINCL)

hash-test: $(SRCS) $(INCL) srcs/hash/hash_test/hash_test.c
	make -C $(LIBFT)
	gcc -o hash-test srcs/hash/hash_test/hash_test.c $(SRCS) -I$(INCL) -L$(LIBFT) -lft -I$(LIBFTINCL)
