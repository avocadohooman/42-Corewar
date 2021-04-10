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
#include <stdlib.h>

typedef struct	s_test
{
	char		*value;
	int			expected_type;
}				t_test;

static const t_test	g_table[] = {
	{"", TOKEN_EOF},
	{" ", TOKEN_EOF},
	{"label", TOKEN_IDENTIFIER},
	{"123", TOKEN_IDENTIFIER},
	{"r12", TOKEN_IDENTIFIER},
	{"label_two", TOKEN_IDENTIFIER},
	{".command", TOKEN_COMMAND},
	{"\"string with spaces and\t whatever\n\"", TOKEN_STRING},
	{"\"string without ending", TOKEN_EOF},
	{":", TOKEN_COLON},
	{",", TOKEN_SEPARATOR},
	{"%", TOKEN_DIRECT},
	{"\n", TOKEN_NEWLINE},
	{"!", TOKEN_ILLEGAL},
	{"          asd", TOKEN_IDENTIFIER},
	{"#comment\n", TOKEN_NEWLINE},
	{"#comment", TOKEN_EOF},
	{"\r\n", TOKEN_NEWLINE},
	{NULL, 0}
};

const char		*g_type_table[] = {
	[TOKEN_ILLEGAL] = "TOKEN_ILLEGAL",
	[TOKEN_COMMAND] = "TOKEN_COMMAND",
	[TOKEN_STRING] = "TOKEN_STRING",
	[TOKEN_IDENTIFIER] = "TOKEN_IDENTIFIER",
	[TOKEN_COLON] = "TOKEN_COLON",
	[TOKEN_DIRECT] = "TOKEN_SEPARATOR",
	[TOKEN_NEWLINE] = "TOKEN_NEWLINE",
	[TOKEN_EOF] = "TOKEN_EOF"
};

int		main(void)
{
	int		test;
	int		success;
	t_lexer	*lexer;
	t_token	*token;

	success = 0;
	test = -1;
	while (g_table[++test].value)
	{
		lexer = init_lexer((char *)g_table[test].value, ft_strlen(g_table[test].value));
		if (!(token = lex_get_next_token(lexer)))
		{
			ft_printf("[ TEST:%d ]: FAILED\t--\tGot NULL, expected non-NULL token\n", test);
			continue ;
		}
		if (token->type != g_table[test].expected_type)
			ft_printf("[ TEST:%d ]: FAILED\t--\tExpected type %s, got %s\n",
					test,
					g_type_table[g_table[test].expected_type],
					g_type_table[token->type]);
		else
			success++;
	}
	ft_printf("[ TEST COMPLETED ]: %d/%d tests succesfull\n", success, test);
	if (success != test)
		return (1);
	return (0);
}
