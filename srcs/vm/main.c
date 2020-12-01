/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:54:48 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 15:36:06 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"
#include <stdio.h>

int main(void)
{
    t_buffer b;

    printf("hello vm\n");
    if (!new_buffer(&b, 10))
        return (1);

    for (int i = 0; i < 20; i++)
    {
        if (!insert_buffer(&b, "asd ", 4))
            return (1);
    }

    printf("%s\n", b.data);
    printf("%zu\n", b.size);
    printf("%zu\n", b.used);


    return (0);
}