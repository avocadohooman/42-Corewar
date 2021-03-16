/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:31:29 by gmolin            #+#    #+#             */
/*   Updated: 2021/03/16 19:31:37 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "libft.h"

typedef enum	e_error_type
{
	USAGE,
	MISSING_ARG,
	INVALID_TOKEN,
	INVALID_FILE,
	BUFFER,
	GET_NEXT_LINE,
	INVALID_ARG,
	MALLOC,
	INVALID_STATEMENT,
	LONG_NAME_COMMENT
}				t_error_type;

void			print_error(int type);

#endif
