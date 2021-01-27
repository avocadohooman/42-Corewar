/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:54:25 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/26 16:15:44 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H
# include "hash.h"

typedef struct	s_label
{
	t_hashnode	node;
	int			value;
}				t_label;

t_label			*new_label(char *label_key, int value);
t_label			*label_upsert(t_hash **map, t_label *label);
t_label			*label_findby_key(t_hash *map, char *key);

#endif
