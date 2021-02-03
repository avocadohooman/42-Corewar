/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:54:25 by npimenof          #+#    #+#             */
/*   Updated: 2021/02/03 11:32:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H
# include "libft.h"

typedef struct	s_label
{
	t_list		nexxt;
	char		*label;
	int			value;
	struct s_label	*next;
}				t_label;

t_label			*new_label(char *label);
int				label_value(t_label *head, char *label);
void			label_push(t_label **list, t_label *label);

#endif
