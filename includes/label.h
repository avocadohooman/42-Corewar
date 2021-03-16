/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:54:25 by npimenof          #+#    #+#             */
/*   Updated: 2021/03/16 19:33:42 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H
# include "libft.h"

typedef struct	s_label
{
	t_list			nexxt;
	char			*label;
	int				value;
	struct s_label	*next;
}				t_label;

t_label			*new_label(char *label);
int				label_value(t_label *head, char *label);
void			label_push(t_label **list, t_label *label);

#endif
