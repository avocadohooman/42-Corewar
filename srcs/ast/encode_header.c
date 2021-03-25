/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:14:00 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 13:42:40 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*encode_header(t_ast *header)
{
	int				i;
	unsigned char	*buf;
	char			*name;
	char			*comment;
	t_buf			*bufio;

	if (!(bufio = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = -1;
	while (++i < header->compound_size)
	{
		if (header->compound_value[i]->command != NULL &&
			!strcmp(header->compound_value[i]->command, ".name"))
			name = header->compound_value[i]->string;
		if (header->compound_value[i]->command != NULL &&
			!strcmp(header->compound_value[i]->command, ".comment"))
			comment = header->compound_value[i]->string;
	}
	buf = encode_output(name, comment, header->body_byte_size);
	if (!(buf_insert(bufio, buf, (PROG_NAME_LENGTH + COMMENT_LENGTH + 16))))
		return (NULL);
	free(buf);
	buf = NULL;
	return (bufio);
}
