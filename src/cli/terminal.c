/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 16:28:32 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 18:09:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		sig_catch(int signo)
{
	DG("catch %d", signo);	
	tty_reset(STDIN_FILENO);
	exit(0);
}

int			tty_raw(int fd)
{
	struct termios	buf;

	if (ttystate != RESET)
		return (-1);
	if (tcgetattr(fd, &buf) < 0)
		return (-1);
	save = buf;
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	buf.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag |= CS8;
	buf.c_oflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSAFLUSH, &buf))
		return (-1);
	if (tcgetattr(fd, &buf) < 0)
	{
		tcsetattr(fd, TCSAFLUSH, &save);
		return (-1);
	}
	if ((buf.c_lflag & (ECHO | ICANON | IEXTEN))
		|| (buf.c_iflag & (BRKINT| ICRNL | INPCK | ISTRIP | IXON))
		|| (buf.c_cflag & (CSIZE | PARENB | CS8)) != CS8
		|| (buf.c_oflag & OPOST) || buf.c_cc[VMIN] != 1
		|| buf.c_cc[VTIME] != 0)
	{
		tcsetattr(fd, TCSAFLUSH, &save);
		return (-1);
	}
	ttystate = RAW;
	ttysavefd = fd;
	return (0);
}

int			tty_reset(int fd)
{
	if (ttystate == RESET)
		return (0);
	if (tcsetattr(fd, TCSAFLUSH, &save) < 0)
		return (-1);
	ttystate = RESET;
	return (0);
}

void		tty_atexit(void)
{
	if (ttysavefd >= 0)
		tty_reset(ttysavefd);
}

void		configure_client(int fd)
{
	signal(SIGINT, sig_catch);
	signal(SIGQUIT, sig_catch);
	signal(SIGTERM, sig_catch);
	if (tty_raw(fd) < 0)
		ft_usage("tty error");
}
