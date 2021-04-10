/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:22:51 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/02 18:31:04 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstclone(t_list *list)
{
	t_list	*result;

	if (list == NULL)
		return (NULL);
	result = ft_lstcontent(list->content);
	result->next = ft_lstclone(list->next);
	return (result);
}
