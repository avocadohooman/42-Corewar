/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:27:43 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/17 17:27:45 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "encoder.h"
#include "file.h"
#include "parser.h"

int			create_file(char *name)
{
	char	*out;
	char	*tmp;
	int		fd;

	if (!(out = ft_memalloc(sizeof(char) * (ft_strlen(name) + 3))))
		exit(1);
	if (!(tmp = ft_strrchr(name, '/')))
		tmp = name;
	else
		tmp += 1;
	ft_strcpy(out, tmp);
	ft_strcpy(ft_strrchr(out, '.'), ".cor");
	if ((fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		exit(1);
	free(out);
	return (fd);
}

t_ast		*asm_parse(t_buf *file)
{
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*root;

	if (!(lexer = init_lexer(file->data, file->used)))
		return (NULL);
	if (!(parser = new_parser(lexer)))
		return (NULL);
	root = parser_parse(parser);
	free_lexer(&lexer);
	free_parser(&parser);
	return (root);
}

int			main(int argc, char **argv)
{
	t_buf			input_file;
	t_buf			*output_file;
	t_ast			*root;
	int				fd;

	if (argc != 2 || !file_extension(argv[1], FILE_EXT))
		print_error(INVALID_FILE);
	input_file = buf_read(argv[1]);
	if (!(root = asm_parse(&input_file)))
		return (1);
	if (!(output_file = encode_ast(root)))
		return (1);
	fd = create_file(argv[1]);
	buf_write(output_file, fd);
	close(fd);
	exit(0);
	return (0);
}
