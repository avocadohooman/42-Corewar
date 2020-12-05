/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_jmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:55:47 by seronen           #+#    #+#             */
/*   Updated: 2020/12/05 15:02:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_track     *trackadd(t_track **alst, t_track *new)
{
	if (*alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (new)
		*alst = new;
}

t_track     *new_tracker(t_ass *ass, char *label)
{
	t_track *new;

	if (!(new = (t_track*)malloc(sizeof(t_track))))
		return NULL;
	new->jmp_bytes = 0;
	new->labelnb = 0;
	new->label = label;
	new->next = NULL;
	trackadd(&ass->track, new);
	return new; 
}

int			fetch_jmp(t_track *head, char *key)
{
	t_track *tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->label))
			return tmp->jmp_bytes * -1;
		tmp = tmp->next;
	}
	return 0;
}

void        track_jmps(t_ass *ass, t_instruction *ins)
{
	int     bytes;
	t_track *tmp;

	bytes += get_component_size(ass, ins->statement);
	if (ins->label)
		new_tracker(ass, ins->label);
	tmp = ass->track;
	while (tmp)
	{
		tmp->jmp_bytes += bytes;
		tmp = tmp->next;
	}
}
