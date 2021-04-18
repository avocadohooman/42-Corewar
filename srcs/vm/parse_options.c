/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:52:36 by seronen           #+#    #+#             */
/*   Updated: 2021/04/18 15:06:29 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_option(char *opt)
{
	if (!opt)
		return (NONE);
	if (!ft_strcmp(opt, DUMP_LITERAL))
		return (DUMP);
	if (!ft_strcmp(opt, LLDFIX_LITERAL))
		return (LLD_FIX);
	if (!ft_strcmp(opt, PRETTY_LITERAL))
		return (PRETTYDUMP);
	return (NONE);
}

int		get_dump_cycle(char *str)
{
	int i;
	int nb;

	i = 0;
	if (!str)
		print_error(MISSING_ARG);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(INVALID_ARG);
		i++;
	}
	nb = ft_atoi(str) + 1;
	if (nb < 1)
		print_error(INVALID_ARG);
	return (nb);
}

int		toggle_option(int opt_id, char **args)
{
	int res;

	res = 1;
	if (opt_id == DUMP || opt_id == PRETTYDUMP)
	{
		res = get_dump_cycle(args[1]);
		args[1] = NULL;
	}
	args[0] = NULL;
	return (res);
}

char	**parse_options(t_vm *vm, char **args, int ac)
{
	int i;
	int opt_id;

	i = 0;
	while (i < ac)
	{
		if (args[i] && args[i][0] == '-')
		{
			opt_id = check_option(args[i]);
			if (opt_id)
				vm->options[opt_id] = toggle_option(opt_id, &args[i]);
			if (opt_id == PRETTYDUMP)
			{
				vm->options[DUMP] = vm->options[PRETTYDUMP];
				vm->options[PRETTYDUMP] = 1;
			}
		}
		i++;
	}
	return (args);
}
