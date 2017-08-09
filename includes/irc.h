/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:34:23 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 19:00:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
#define IRC_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/select.h>
# include <sys/time.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <stdarg.h>

# include "types.h"
# include "msg.h"
# include "database.h"
# include "cli.h"
# include "parse.h"
# include "cmds.h"
# include "prompt.h"

/* Class of Users */

# define CLIENT		1 << 0
# define OPERATOR	1 << 1
# define SERVICE	1 << 2

/* Server side */

# define RDBUFSIZE	513

struct s_streamcmd
{
	char	*buf;
	char	*uid;
};

struct s_server
{
	char		name[64];
//	char		*hostmask;
	t_hashtab	clients;
	t_hashtab	users;
	t_hashtab	channels;
	t_hashtab	servers;
	t_list		*cmds;
};

int	daemonize(void);

void	server_loop(int dest, int s_sock, t_server *server);

void	init_serv(char *name, t_server *server);

void	manage_sockets(int dest, int s_sock, int *maxfd, fd_set *allset, t_server *server);

void	manage_cmds(t_server *server);

void	execute_cmd(t_cmd *cmd, t_server *server);

void	accept_cli(fd_set *allset, int sock, int *maxfd, t_server *server);

void	read_sockets(fd_set *rset, fd_set *allset, t_server *server, int dest);

void	write_sockets(fd_set *wset, fd_set *allset, t_server *server);

int	cirbuf_read(int fd, char *cirbuf, int size, int *index);

void	first_parse(char *buffer, int index, t_server *server, char *uid);

void	streamcmd_destroy(void *content, size_t size);

void	broadcast(void);

/* Lib Server */

void	construct_msg(char *uid, t_server *server, ...);

/* Debug */

int	print_bucket(void *content, void *data);

int	print_cmds(void *content, void *data);

int	print_tokens(void *content, void *data);

int	print_cmd(void *content, void *data);

int	print_params(void *content, void *data);

#endif
