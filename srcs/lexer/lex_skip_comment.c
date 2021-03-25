/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_skip_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:22:42 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 15:24:19 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lex_skip_comment(t_lexer *lexer)
{
	while (lexer->c && lexer->c != '\n')
		lex_advance(lexer);
}
