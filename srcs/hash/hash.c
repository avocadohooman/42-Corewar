/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:35:04 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/26 23:04:44 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

t_hashnode		*hash_findby_key(t_hash *map, unsigned char *key)
{
	t_hashnode	*node;

	node = map->table[map->key(key)];
	if (!(node = hashnode_find(node, key)))
		return (NULL);
	return (node);
}

t_hash			*hash_upsert(t_hash **map, t_hashnode *newnode)
{
	t_hashnode	*node;
	size_t		index;

	index = (*map)->key(newnode->key);
	node = (*map)->table[index];
	if ((node = hashnode_update(&node, newnode)))
	{
		(*map)->table[index] = node;
		return (*map);
	}
	hashnode_add(&((*map)->table[index]), newnode);
	return (*map);
}

static size_t	hasher(char *key)
{
	size_t	hashvalue;

	hashvalue = 0;
	while (key && *key)
	{
		hashvalue += *key;
		hashvalue = (hashvalue * *key) % TABLESIZE;
		key++;
	}
	return (hashvalue);
}

t_hash		*new_hashtable(void)
{
	t_hash	*map;

	if (!(map = ft_memalloc(sizeof(t_hash))))
		return (NULL);
	if (!(map->table = ft_memalloc(sizeof(t_hashnode *) * TABLESIZE)))
		return (NULL);
	map->key = hasher;
	map->size = TABLESIZE;
	map->used = 0;
}
