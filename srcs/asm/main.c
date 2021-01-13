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
#include <stdio.h> // delete


int         check_registry(char *string) 
{
    int len;

    len = ft_strlen(string);
    if (string[0] == 'r' && !ft_strchr(string, '-'))
    {
        if (len == 2 && string[1] != '0' && ft_isdigit(string[1]))
            return (1);
        else if (len == 3 && ft_atoi(&string[1]) != 0 && ft_atoi(&string[2]) != 0)
            return (1);
    }
    return (0);
}

int         check_dir_ind(char *string)
{
    int     i;
    int     zeros;

    i = 0;
    zeros = 0;
    while (string[i]) 
    {
        if (string[i] == '0')
            zeros++;
        i++;
    }
    if (string[0] == '-') 
    {
         if (ft_atoi(string) && (ft_strlen(&string[1]) == zeros + ft_ndigits(ft_atoi(string))))
            return (1);
    }
    else if (ft_atoi(string) && (ft_strlen(string) == zeros + ft_ndigits(ft_atoi(string))))
        return (1);
    return (0);
}

int			main(int argc, char **argv)
{
	t_file		input_file;
	t_file		output_file;
	t_lexer		*lexer;
	t_parser	*parser;
	int			bytes;
	
	if (argc != 2 || !file_extension(argv[1], FILE_EXT))
		print_error(INVALID_FILE);

	input_file = read_file(argv[1]);
	lexer = init_lexer(input_file.data, input_file.used);
	parser = new_parser(lexer);
	parser_parse(parser, NULL);
    printf("check registry: %d\ncheck dir || ind value: %d\n", check_registry("r-1"), check_dir_ind("-0000000000000000000000000000000000000000000021343"));

	// bytes = write_file(1, &input_file);
	// printf("wrote %d bytes\n", bytes);

	// new_file(&output_file, 1024);
	// insert_file(&output_file, "haha\n", 5);
	// write_file(1, &output_file);
	return (0);
}
