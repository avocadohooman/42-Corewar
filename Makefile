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
FLAGS = -Wall -Werror -Wextra
VM_MAIN = srcs/vm/main.c srcs/error.c \

FILE = srcs/file/file.c srcs/file/read.c srcs/file/write.c \

TOKEN = srcs/token/token.c \

LEXER = srcs/lexer/lexer.c srcs/lexer/lex_get_command.c \
		srcs/lexer/lex_get_identifier.c srcs/lexer/lex_get_operator.c \
		srcs/lexer/lex_get_string.c srcs/lexer/lex_skip_comment.c \
		srcs/lexer/lex_skip_whitespace.c \

PARSER = srcs/parser/parser.c srcs/parser/parser_header.c \
		srcs/parser/parser_body_statement.c srcs/parser/parser_body.c \
		srcs/parser/parser_body_args.c srcs/parser/parser_body_args_inner.c \
		srcs/parser/parser_error.c \

AST = srcs/ast/ast.c srcs/ast/compound_insert.c srcs/ast/encode_statement.c \
		srcs/ast/init_ast.c srcs/ast/encode_body.c srcs/ast/encode_compound.c \
		srcs/ast/encode_header.c  srcs/ast/encode_instruction.c \
		srcs/ast/assign_data_to_struct.c \

LABEL = srcs/label/label.c \

OPCODE = srcs/opcode/opcode.c \

ENCODER = srcs/encoder/encoder_header/encoder.c

SRCS = 	srcs/vm/args.c srcs/vm/read_files.c srcs/vm/arena.c srcs/vm/initiate_carriage.c srcs/vm/decrypt.c srcs/vm/player.c \
		srcs/vm/funcs/helper_functions/get_arg_value.c srcs/vm/funcs/helper_functions/write_bytes.c srcs/vm/funcs/helper_functions/read_bytes.c\
		srcs/vm/funcs/helper_functions/copy_carriage.c srcs/vm/memspace.c srcs/vm/statement.c srcs/vm/statement_args.c \
		srcs/vm/parse_options.c srcs/vm/funcs/live.c srcs/vm/funcs/ld.c  srcs/vm/funcs/st.c  srcs/vm/funcs/add.c \
		srcs/vm/funcs/sub.c srcs/vm/funcs/and.c  srcs/vm/funcs/or.c  srcs/vm/funcs/xor.c \
		srcs/vm/funcs/zjmp.c srcs/vm/funcs/ldi.c  srcs/vm/funcs/sti.c  srcs/vm/funcs/fork.c \
		srcs/vm/funcs/lld.c srcs/vm/funcs/lldi.c  srcs/vm/funcs/lfork.c  srcs/vm/funcs/aff.c \
		srcs/vm/battle_loop.c \
		srcs/vm/carriage_check.c \

ASM = srcs/asm/main.c srcs/error.c $(TOKEN) $(LEXER) $(PARSER) $(AST) \
		$(ENCODER) $(LABEL) $(OPCODE) $(FILE) \

INCL = ./includes
LIBFT = ./libft
LIBFTINCL = $(LIBFT)/libft/includes  -I ./libft/ft_printf/includes/

.PHONY: all
all: $(VM_NAME) $(ASM_NAME)

$(VM_NAME): $(SRCS) $(INCL) $(VM_MAIN)
	make -C $(LIBFT)
	gcc -o $(VM_NAME) $(FLAGS) $(VM_MAIN) -I$(INCL) $(SRCS) $(FILE) \
	-L$(LIBFT) -lft -I$(LIBFTINCL)

$(ASM_NAME): $(INCL) $(ASM)
	make -C $(LIBFT)
	gcc -o $(ASM_NAME) $(FLAGS) $(ASM) -I$(INCL) \
	-L$(LIBFT) -lft -I$(LIBFTINCL)

.PHONY: clean
clean:
	make clean -C $(LIBFT)

.PHONY: fclean
fclean:
	make fclean -C $(LIBFT)
	rm -f $(VM_NAME)
	rm -f $(ASM_NAME)
	rm -f $(LEXER_TEST_NAME)
	rm -f file-test
	rm -f encoder-test
	rm -f hash-test

.PHONY: re
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
