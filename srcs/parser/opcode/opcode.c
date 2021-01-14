/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:49:27 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/13 19:22:11 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

void            parser_parse_lfork(t_parser *parser)
{
}

void            parser_parse_sti(t_parser *parser)
{
    printf("hello parser_parse_sti\n");
    parser_consume(parser, TOKEN_IDENTIFIER);
    if (!is_registry(parser->prev_token->value))
        return ; // error
    while (parser->current_token->type == TOKEN_SEPARATOR)
    {
        parser_consume(parser, TOKEN_SEPARATOR);
        parser_parse_body_args(parser);
    }
}

void            parser_parse_fork(t_parser *parser)
{
}

void            parser_parse_lld(t_parser *parser)
{
}

void            parser_parse_ld(t_parser *parser)
{
}

void            parser_parse_add(t_parser *parser)
{
}

void            parser_parse_zjmp(t_parser *parser)
{
}

void            parser_parse_sub(t_parser *parser)
{
}

void            parser_parse_ldi(t_parser *parser)
{
}

void            parser_parse_or(t_parser *parser)
{
}

void            parser_parse_st(t_parser *parser)
{
}

void            parser_parse_aff(t_parser *parser)
{
}

void            parser_parse_live(t_parser *parser)
{
}

void            parser_parse_xor(t_parser *parser)
{
}

void            parser_parse_lldi(t_parser *parser)
{
}

void            parser_parse_and(t_parser *parser)
{
}
