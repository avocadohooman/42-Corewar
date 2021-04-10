/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:26:06 by hopham            #+#    #+#             */
/*   Updated: 2020/01/02 15:14:48 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "limits.h"

# define BLUE "\033[0;34m"
# define BGREEN "\033[1;32m"
# define BRED "\033[1;31m"
# define BBLUE "\033[1;34m"

typedef	struct	s_printf
{
	const char	*format;
	char		*f_copy;
	va_list		args;
	int			len;
	size_t		i;
	int			width;
	int			precision;
	char		*specifier_list;
	char		specifier_char;
	char		*flags;
	char		flag_convert[6];
	char		*len_mods;
	char		len_mods_convert[3];
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		*parse_convert(t_printf *list);
t_printf		*parse_field_width(t_printf *list);
t_printf		*parse_specifier(t_printf *list);
t_printf		*parse_precision(t_printf *list);
t_printf		*parse_len_mod(t_printf *list);
int				treatment(t_printf *list);
void			display_gap(t_printf *list, char c, int len, int update_len);
t_printf		*display_c(t_printf *list);
t_printf		*display_s(t_printf *list);
t_printf		*display_i(t_printf *list);
t_printf		*display_o(t_printf *list);
t_printf		*display_u(t_printf *list);
t_printf		*display_x(t_printf *list);
t_printf		*display_p(t_printf *list);
t_printf		*display_f(t_printf *list);
t_printf		*display_other(t_printf *list);
t_printf		*display_all(t_printf *list);
void			display_exception_char(char c, t_printf *list);
char			get_sign(t_printf *list, double nb);
void			ft_putnbrmax_fd(uintmax_t n, int fd);

#endif
