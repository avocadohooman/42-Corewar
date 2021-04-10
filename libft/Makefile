# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:49:26 by npimenof          #+#    #+#              #
#    Updated: 2020/11/19 17:25:58 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_iswhitespace.c ft_itoa.c ft_lstadd.c\
		ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memdel.c ft_memmove.c ft_memset.c ft_ndigits.c ft_nwords.c ft_putchar.c\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
		ft_putstr.c ft_putstr_fd.c ft_splitdigits.c ft_strcat.c ft_strchr.c\
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
		ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_get_next_line.c ft_pow.c ft_sqrt.c\
		ft_strcspn.c ft_strspn.c ft_abs.c ft_fabs.c ft_creplace.c ft_cnreplace.c\
		ft_pow_e.c ft_itoa_base.c ft_nchars.c ft_sign.c ft_del_args.c\
		ft_ignore_neg.c ft_lfmod.c ft_del_lstcontent.c ft_lstadd_sorted.c\
		ft_lstrev.c ft_lstlen.c ft_lstpop.c ft_lstcontent.c ft_lstpush.c\
		ft_lstclone.c ft_malloctype.c

OBJS =  ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
		ft_isdigit.o ft_isprint.o ft_iswhitespace.o ft_itoa.o ft_lstadd.o\
		ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o\
		ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o\
		ft_memdel.o ft_memmove.o ft_memset.o ft_ndigits.o ft_nwords.o ft_putchar.o\
		ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o\
		ft_putstr.o ft_putstr_fd.o ft_splitdigits.o ft_strcat.o ft_strchr.o\
		ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o\
		ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o\
		ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o\
		ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o\
		ft_strtrim.o ft_tolower.o ft_toupper.o ft_get_next_line.o ft_pow.o ft_sqrt.o\
		ft_strcspn.o ft_strspn.o ft_abs.o ft_fabs.o ft_creplace.o ft_cnreplace.o\
		ft_pow_e.o ft_itoa_base.o ft_nchars.o ft_sign.o ft_del_args.o\
		ft_ignore_neg.o ft_lfmod.o ft_del_lstcontent.o ft_lstadd_sorted.o\
		ft_lstrev.o ft_lstlen.o ft_lstpop.o ft_lstcontent.o ft_lstpush.o\
		ft_lstclone.o ft_malloctype.o

INCL = ./includes

all: $(NAME) $(INCL)/libft.h $(INCL)/get_next_line.h

$(NAME): $(SRCS)
	gcc $(FLAGS) -c $(SRCS) -I$(INCL)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all