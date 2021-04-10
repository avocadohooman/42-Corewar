# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:56:43 by hopham            #+#    #+#              #
#    Updated: 2020/01/02 15:15:27 by hopham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = ./libft/libft.a
LIB_FODER = ./libft/
FLAGS = -Wextra -Werror -Wall

SRCS = ./ft_printf/srcs/
C_FUNCTIONS = ft_printf parse_field_width parse_convert display_gap treatment \
			display_s display_i display_p display_o display_all display_c \
			display_u display_x display_f display_other parse_specifier \
			parse_len_mod parse_precision \
			display_exception_char get_sign ft_putnbrmax_fd

C_FILES = $(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
OBJ = $(addsuffix .o, $(C_FUNCTIONS))
LIB_OBJ = ./libft/*.o

INCLUDES = -I ./ft_printf/includes/ -I ./libft/includes/

all: $(NAME)

$(NAME): all
	make -C $(LIB_FODER)
	@cp $(LIB) ./$(NAME)
	gcc $(FLAGS) $(INCLUDES) -c $(C_FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) $(LIB_OBJ)

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: clean fclean re all
