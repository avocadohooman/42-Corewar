/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroorann <seroorane@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:45:48 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 14:24:38 by seroorantane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ast.h"
#include "encoder.h"
#include "file.h"
#include "parser.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_file			input_file;
	t_lexer			*lexer;
	t_parser		*parser;
	t_ast			*root;
	unsigned char	*buf;
	int				fd;
	char			*out;
	
	if (argc != 2 || !file_extension(argv[1], FILE_EXT))
		print_error(INVALID_FILE);
	input_file = read_file(argv[1]);
	lexer = init_lexer(input_file.data, input_file.used);
	parser = new_parser(lexer);
	root = parser_parse(parser);
    buf = visit_ast(root);
	out = ft_memalloc(sizeof(char) * (ft_strlen(argv[1] + 2)));


	ft_strcpy(out, ft_strrchr(argv[1], '/') + 1);
	ft_strcpy(ft_strchr(out, '.'), ".cor");
	if ((fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (1);
	write(fd, buf, root->body_byte_size + HEADER_SIZE);
	exit(0);
	return (0);
}
