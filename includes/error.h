/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:26:33 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 14:2826 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "libft.h"

char	*g_errors[] = {"Usage: ./asm [champion_file.s]", "Missing argument!",
						"three"};

typedef enum	e_error_type
{
	USAGE,
	MISSING_ARG,
	INVALID_TOKEN,
}				t_error_type;

void	print_error(t_error_type type);

#endif