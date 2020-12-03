/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:54:30 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/03 14:01:47 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>

void	errorp(char *e)
{
	printf("Error: %s\n", e);
	exit(1);
}

void	tokenp(t_token *t)
{
	printf("token: {\n\tvalue: %s\n\ttype: %d\n}\n", t->value, t->type);
}

int		main(int ac, char **av)
{
	t_lexer	*lexer;
	t_token	*token;
	char	*input;
	char	*expected;
	int		len;

	if (ac == 3)
	{
		input = av[1];
		expected = av[2];
		len = ft_strlen(input);
		lexer = init_lexer(input, len);
		if (memcmp(input, lexer->data, len))
			errorp("Lexer content not matching with the input data");
		if (!(token = lex_get_next_token(lexer)))
			errorp("Failed to get next token");
		tokenp(token);
	}
	else
		printf("Missing argument\n");
	return (0);
}