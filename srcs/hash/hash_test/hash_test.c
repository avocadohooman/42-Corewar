/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:19:23 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/28 08:45:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label.h"
#include <stdio.h>

int		main(void)
{
	t_hash		*map;
	t_label		*label1;
	t_label		*label2;
	t_label		*found1;
	t_label		*found2;
	t_label		*found3;
	t_label		*found4;
	
	if (!(map = new_hashtable()))
		return (1);
	if (!(label1 = new_label("12345", 123)))
		return (1);
	if (!(label2 = new_label("54321", 22)))
		return (1);
	if (!label_upsert(&map, label1))
		return (1);
	if (!label_upsert(&map, label2))
		return (1);
	if (!(found1 = label_findby_key(map, "12345")))
		return (1);
	printf("found1.value: %d\n", found1->value);
	found1->value = 321;
	if (!(found2 = label_findby_key(map, "54321")))
		return (1);
	printf("found2.value: %d\n", found2->value);
	found2->value = 42;
	if (!label_upsert(&map, found1))
		return (1);
	if (!label_upsert(&map, found2))
		return (1);
	if (!(found3 = label_findby_key(map, "12345")))
		return (1);
	printf("found3.value: %d\n", found3->value);
	if (!(found4 = label_findby_key(map, "54321")))
		return (1);
	printf("found4.value: %d\n", found4->value);
	printf("passed all\n");
	return (0);
}
