/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:29:03 by seronen           #+#    #+#             */
/*   Updated: 2021/03/25 04:16:56 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define DUMP_LITERAL "-dump"
# define PLAYERNB_LITERAL "-n"
# define LLDFIX_LITERAL "-lldfix"
# define DEBUG_LITERAL "-debug"

# define OPT_AMOUNT 4

enum {
	NONE,
	DUMP,
	LLD_FIX,
	DEBUG
};

#endif
