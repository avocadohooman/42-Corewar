/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:29:03 by seronen           #+#    #+#             */
/*   Updated: 2021/04/09 17:18:46 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define DUMP_LITERAL "-dump"
# define PLAYERNB_LITERAL "-n"
# define LLDFIX_LITERAL "-lldfix"

# define OPT_AMOUNT 3

enum {
	NONE,
	DUMP,
	LLD_FIX,
};

#endif
