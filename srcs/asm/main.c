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
#include "file.h"
#include "parser.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_file		input_file;
	t_file		output_file;
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*root;
	int			bytes;
	
	if (argc != 2 || !file_extension(argv[1], FILE_EXT))
		print_error(INVALID_FILE);
	input_file = read_file(argv[1]);
	lexer = init_lexer(input_file.data, input_file.used);
	parser = new_parser(lexer);
	root = parser_parse(parser);
    
	// bytes = write_file(1, &input_file);
	// printf("wrote %d bytes\n", bytes);

	// new_file(&output_file, 1024);
	// insert_file(&output_file, "haha\n", 5);
	// write_file(1, &output_file);
	return (0);
}
