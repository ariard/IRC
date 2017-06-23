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

# include "database.h"
# include "cli.h"

/* Class of Users */

# define CLIENT		1 << 0
# define OPERATOR	1 << 1
# define SERVICE	1 << 2


/* Server side */

# define RDBUFSIZE	513

struct s_channel
{
	char	name[51];
	t_list	*members;
	int		mode;
	int		scope;
};

typedef struct s_channel		t_channel;


struct s_user
{
	char	*server;
	char	nickname[10];
	char	*username;
	char	*hostname;
	char	mode;
};

typedef struct s_user			t_user;

struct s_server
{
	char		name[64];
//	char		*hostmask;
	t_hashtab	clients;
	t_hashtab	channels;
	t_hashtab	servers;
	t_list		*cmds;
};

typedef struct s_server			t_server;

struct s_cmd
{
	char	prio;
	char	*msg;
};

typedef struct s_cmd			t_cmd;

int		daemonize(void);

void	server_loop(int dest, int s_sock, t_server *server);

void	init_serv(char *name, t_server *server);

void	manage_sockets(int dest, int s_sock, int *maxfd, fd_set *allset, t_server *server);

void	execute_cmds(t_server *server);

void	accept_cli(fd_set *allset, int sock, int *maxfd, t_server *server);

void	read_sockets(fd_set *rset, fd_set *allset, t_server *server, int dest);

void	write_sockets(fd_set *wset, fd_set *allset, t_server *server);

int		cirbuf_read(int fd, char *cirbuf, int size, int *index);

void	first_parse(char *buffer, int index, t_server *server);

/* Debug */

int		print_bucket(void *content, void *data);

int		print_cmds(void *content, void *data);

#endif


// grammar parsing .h
// error replies .h
//
