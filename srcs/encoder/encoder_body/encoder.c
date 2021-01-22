/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:08:38 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/22 18:21:31 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h> // delete
#include "encoder.h"

void        encoding_hub(t_ast *root) 
{
	visit_ast(root);
}