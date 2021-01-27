/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:23:00 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/26 23:04:20 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

t_hashnode	*new_hashnode(unsigned char *key)
{
	t_hashnode	*node;

	if (!(node = ft_memalloc(sizeof(t_hashnode))))
		return (NULL);
	node->key = ft_strdup(key);
	node->next.next = NULL;
	node->next.content = NULL;
	node->next.content_size = 0;
	return (node);
}

t_hashnode		*hashnode_update(t_hashnode **node, t_hashnode *newnode)
{
	t_hashnode	*tmp;
	t_hashnode	*prev;
	int			len;

	len = ft_strlen(newnode->key);
	tmp = *node;
	if (tmp && !ft_memcmp(newnode->key, tmp->key, len))
	{
		newnode->next.next = tmp->next.next;
		*node = newnode;
		return (*node);
	}
	while (tmp && ft_memcmp(newnode->key, tmp->key, len))
	{
		prev = tmp;
		tmp = next(tmp);
	}
	if (tmp)
	{
		newnode->next.next = tmp->next.next;
		prev->next.next = (t_list *)newnode;
		return (*node);
	}
	return (NULL);
}

t_hashnode		*hashnode_find(t_hashnode *node, unsigned char *key)
{
	t_hashnode *tmp;

	tmp = node;
	while (tmp)
	{
		if (!ft_memcmp(key, tmp->key, ft_strlen(key)))
			return (tmp);
		tmp = next(tmp);
	}
	return (NULL);
}

t_hashnode	*next(t_hashnode *node)
{
	return ((t_hashnode *)node->next.next);
}

void		hashnode_add(t_hashnode **head, t_hashnode *newnode)
{
	ft_lstadd((t_list **)&(*head), (t_list *)newnode);
}
