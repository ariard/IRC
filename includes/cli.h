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
#include <term.h>

static struct termios	save;
static int				ttysavefd = -1;
static enum { RESET, RAW, CBREAK } ttystate = RESET;

# define CLIBUF		512

int		tty_raw(int fd);

int		tty_reset(int fd);

void		tty_atexit(void);

void		configure_client(int fd);

/* Termcaps functions */

extern char			*tgoto(const char *cstring, int hpos, int vpos);

extern int			tputs(const char *str, int affcnt, int (*putc)(int));

extern int			tgetent(char *bp, const char *name);

extern char			*tgetstr(char *name, char **area);

extern int			tgetnum(char *name);

#endif
