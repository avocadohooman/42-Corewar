/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_jmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:55:47 by seronen           #+#    #+#             */
/*   Updated: 2021/01/23 12:06:39 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

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
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->label))
		{
			return (tmp->label_start - from);
		}
		tmp = tmp->next;
	}
	return 0;
}

int         find_next_statment(t_instruction *ins)
{
    t_instruction *tmp;

    tmp = ins;
    while(!tmp->statement)
        tmp = tmp->next;
    return (tmp->statement->component_size);
}

void        track_jmps(t_ass *ass, t_instruction *ins)
{
	t_instruction *tmp;
	int pos;

	pos = 0;
	tmp = ins;
	while (tmp)
	{
        ass->size = 0;
        if (tmp->statement)
        {
            ass->size += tmp->statement->component_size;
            if (tmp->label)
                new_tracker(ass, tmp->label, pos);
            tmp->statement->pos = pos;
            pos += ass->size;
        }
        else if (tmp->label && !tmp->statement)
        {
            ass->size += find_next_statment(tmp);
            new_tracker(ass, tmp->label, pos);
        }
		tmp = tmp->next;
	}
}
