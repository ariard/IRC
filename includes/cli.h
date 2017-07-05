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

# include "irc.h"

# define DFLT	100
# define CR	13

struct	s_keymatch
{
	char	key;
	void	(*f)(char buf[], t_prompt *prompt, int key, int sock);
};

static struct termios	save;
static int				ttysavefd = -1;
static enum { RESET, RAW, CBREAK } ttystate = RESET;

# define CLIBUF		512

int		tty_raw(int fd);

int		tty_reset(int fd);

void		tty_atexit(void);

void		configure_client(int fd);

void		cli_loop(int sock);

void		read_stdin(char buf[], t_prompt *prompt, int sock);

void		read_socket(char buf_stdin[], char buf_socket[], t_prompt *prompt);

void		send_buf(char buf[], t_prompt *prompt, int key, int sock);

void		add_buf(char buf[], t_prompt *prompt, int key, int sock);

#endif
