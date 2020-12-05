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
		srcs/lexer/lexer.c srcs/token/token.c srcs/parser/parser.c \
		srcs/error.c \
		srcs/asm/get_argument_type.c srcs/asm/get_arguments.c srcs/asm/get_component_size.c \
		srcs/asm/get_statement.c 

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

re: fclean all

lexer-test: 
	make -C $(LIBFT)
	gcc -o $(LEXER_TEST_NAME) srcs/lexer/lexer_test/lexer_test.c $(SRCS) -I$(INCL) -L$(LIBFT) -lft -I$(LIBFTINCL)
