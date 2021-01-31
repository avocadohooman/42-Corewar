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
		srcs/vm/args.c srcs/vm/read_files.c srcs/vm/arena.c \
		srcs/ast/ast.c \
		srcs/ast/assign_data_to_struct.c \
		srcs/parser/parser.c srcs/parser/parser_header.c \
		srcs/parser/parser_body.c srcs/parser/parser_args.c \
		srcs/parser/parser_error.c \
		srcs/opcode/opcode.c \
		srcs/hash/hash.c srcs/hash/hashnode.c srcs/hash/labelnode.c \
		srcs/encoder/encoder_header/encoder.c \

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
	gcc $(FLAGS) -o $(VM_NAME) $(VM_MAIN) -I$(INCL) $(SRCS)  \
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
