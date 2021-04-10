# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:46:39 by hopham            #+#    #+#              #
#    Updated: 2021/04/10 13:57:53 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/

FUNCTIONS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_strupcase.c ft_isupper.c \
		ft_atoill.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_lstadd.c ft_isblank.c ft_strrev.c ft_islower.c \
	 ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	 ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdel.c ft_strcapitalize.c ft_strlowcase.c \
	 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	 ft_strrchr.c  ft_strsplit.c ft_strstr.c ft_countwords.c ft_strndup.c \
	 ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strsplitset.c \
	 ft_lstadd_end.c ft_lstcount.c ft_lstrev.c get_next_line.c \
	 ft_ftoa.c ft_itoa_base.c sort_int_tab.c sort_int_tab_des.c \
	 ft_lstnew_str.c ft_strsplit_len.c ft_lstpush.c

C_FILES = $(addprefix $(SRC), $(FUNCTIONS))

OBJECTS = $(FUNCTIONS:.c=.o)

INCLUDES = ./includes/

all: $(NAME)

$(NAME):
	gcc -Wextra -Wall -Werror -I $(INCLUDES) -c $(C_FILES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
