/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_skip_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:22:42 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:57:20 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"

void			lex_skip_comment(t_lexer *lexer)
{
	while (lexer->c && lexer->c != '\n')
		lex_advance(lexer);
}
