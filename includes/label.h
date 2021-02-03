/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:54:25 by npimenof          #+#    #+#             */
/*   Updated: 2021/02/03 09:58:47 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H
# include "hash.h"

typedef struct	s_label1
{
	t_list		nexxt;
	char		*label;
	int			value;
	struct s_label1	*next;
}				t_label1;

typedef struct	s_label
{
	t_hashnode	node;
	int			value;
}				t_label;

t_label			*new_label(char *label_key, int value);
t_label			*label_upsert(t_hash **map, t_label *label);
t_label			*label_findby_key(t_hash *map, char *key);

t_label1		*new_label1(char *label);
void			ft_labeladd(t_label1 **alst, t_label1 *new);
int				label_value(t_label1 *head, char *label);
void			push(t_label1 **list, t_label1 *label);

#endif
