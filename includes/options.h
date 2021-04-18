/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:29:03 by seronen           #+#    #+#             */
/*   Updated: 2021/04/18 14:54:23 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define DUMP_LITERAL "-dump"
# define PLAYERNB_LITERAL "-n"
# define LLDFIX_LITERAL "-lldfix"
# define PRETTY_LITERAL "-prettydump"

# define OPT_AMOUNT 4

enum {
	NONE,
	DUMP,
	LLD_FIX,
	PRETTYDUMP
};

#endif
