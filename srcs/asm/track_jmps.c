/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_jmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:55:47 by seronen           #+#    #+#             */
/*   Updated: 2020/12/08 14:31:39 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		trackadd(t_track **alst, t_track *new)
{
	if (*alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (new)
		*alst = new;
}

t_track     *new_tracker(t_ass *ass, char *label, int pos)
{
	t_track *new;

	if (!(new = (t_track*)malloc(sizeof(t_track))))
		return NULL;
	new->label_start = pos;
	new->label = label;
	new->next = NULL;
	trackadd(&ass->track, new);
	return new; 
}

int			fetch_jmp(t_track *head, char *key, int from)
{
	t_track *tmp;

	tmp = head;
	printf("fetch pos from %d\n", from);
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->label))
			return (tmp->label_start - from);
		tmp = tmp->next;
	}
	return 0;
}

void        track_jmps(t_ass *ass, t_instruction *ins)
{
	t_instruction *tmp;
	int pos;

	pos = 0;
	tmp = ins;
	while (tmp)
	{
		get_component_size(ass, tmp->statement);
		if (tmp->label)
			new_tracker(ass, tmp->label, pos);
		tmp->statement->pos = pos;
		pos += ass->size;
		tmp = tmp->next;
	}
}
