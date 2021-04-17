/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_statement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:16:07 by Gerhard           #+#    #+#             */
/*   Updated: 2021/04/15 16:26:52 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

unsigned char		*encode_arg(t_ast *arg, t_label *labels)
{
	unsigned char	*encoded_arg;
	unsigned char	*buf;
	int				i;
	int				value;

	if (!(encoded_arg = ft_memalloc(sizeof(char) * arg->arg_size)))
		return (NULL);
	if (arg->label)
	{
		if ((value = label_value(labels, arg->label)) < 0)
			print_error(8);
		value -= arg->statement_position;
	}
	else
		value = arg->arg_value;
	i = arg->arg_size + 1;
	buf = encoded_arg;
	while (--i > 0)
	{
		*buf = ((unsigned char *)&value)[i - 1];
		buf++;
	}
	return (encoded_arg);
}

unsigned char		encode_arg_type(t_ast **args, int nb)
{
	unsigned char	code;
	int				i;

	i = -1;
	code = 0;
	while (++i < nb)
	{
		if (args[i]->arg_type == T_REG)
			code |= 1UL << (6 - (i + i));
		else if (args[i]->arg_type == T_DIR)
			code |= 1UL << (7 - (i + i));
		else
		{
			code |= 1UL << (7 - (i + i));
			code |= 1UL << (6 - (i + i));
		}
	}
	return (code);
}

t_buf				*encode_statement(t_ast *stmt)
{
	int				i;
	unsigned char	byte;
	unsigned char	*arg;
	t_buf			*buf_statement;

	byte = stmt->statement;
	if (!(buf_statement = ft_memalloc(sizeof(t_buf))) ||
		!(buf_insert(buf_statement, (char *)&byte, 1)))
		return (NULL);
	if (g_opcode_table[(int)stmt->statement - 1].argument_type)
	{
		byte = encode_arg_type(stmt->statement_args, stmt->statement_n_args);
		if (!(buf_insert(buf_statement, (char *)&byte, 1)))
			return (NULL);
	}
	i = -1;
	while (++i < stmt->statement_n_args)
	{
		if (!(arg = encode_arg(stmt->statement_args[i], stmt->label_list)) ||
		!(buf_insert(buf_statement, (char *)arg,
			stmt->statement_args[i]->arg_size)))
			return (NULL);
		ft_strdel((char **)&arg);
	}
	return (buf_statement);
}
