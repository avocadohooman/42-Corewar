/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:25:13 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 11:36:30 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The isblank() function tests for a space or tab character.  For any
**	locale, this includes the following standard characters:
**	-------------------------------------------------------------------------
**	``\t''      `` ''
**	-------------------------------------------------------------------------
**	In the "C" locale, a successful isblank() test is limited to these
**	characters only.  The value of the argument must be representable as an
**	unsigned char or the value of EOF.
**		RETURN VALUES
**	The isblank() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
