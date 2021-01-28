/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:01:57 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/26 22:37:42 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H
# include "libft.h"

# define TABLESIZE (1024)

typedef struct	s_hashnode
{
	t_list			next;
	unsigned char	*key;
}				t_hashnode;


typedef struct	s_hash
{
	t_hashnode	**table;
    size_t		(*key)(char *);
    size_t		size;
    size_t		used;
}				t_hash;

t_hash			*new_hashtable(void);
t_hash			*hash_upsert(t_hash **map, t_hashnode *newnode);
t_hashnode		*hash_findby_key(t_hash *map, unsigned char *key);

t_hashnode		*new_hashnode(unsigned char *key);
t_hashnode		*hashnode_find(t_hashnode *node, unsigned char *key);
t_hashnode		*hashnode_update(t_hashnode **node, t_hashnode *newnode);
t_hashnode		*next(t_hashnode *node);
void			hashnode_add(t_hashnode **head, t_hashnode *newnode);

#endif
