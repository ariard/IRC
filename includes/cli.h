/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 16:29:09 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 17:11:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
#define CLI_H

#include <termios.h>

static struct termios	save;
static int				ttysavefd = -1;
static enum { RESET, RAW, CBREAK } ttystate = RESET;


int			tty_raw(int fd);

int			tty_reset(int fd);

void		tty_atexit(void);

void		configure_client(int fd);

#endif
