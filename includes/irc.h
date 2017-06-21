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

/* Class of Users */

# define CLIENT		1 << 0
# define OPERATOR	1 << 1
# define SERVICE	1 << 2


/* Server side */

# define RDBUFSIZE	2048

struct s_channel
{
	char	name[51];
	t_list	*members;
	int		mode;
	int		scope;
};

typedef struct s_channel		t_channel;

struct s_client
{
	char	*uid;
	char	*server;
	int		socket;
	char	type;
	char	*wrbuf;
	int		wrindex;
	char	*rdbuf;
	int		rdindex;
};

typedef struct s_client			t_client;

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

void	execute_cmds(void);

void	client_init(t_client *client, int clifd, char *servername);

int		client_cmp(const void *content1, const void *content2);

int		client_print(void *content);

void	accept_cli(fd_set *allset, int sock, int *maxfd, t_server *server);

void	read_sockets(fd_set *rset, fd_set *allset, t_server *server, int dest);

void	write_sockets(fd_set *wset, fd_set *allset, t_server *server);

int		cirbuf_read(int fd, char *cirbuf, int size, int *index);

#endif


// grammar parsing .h
// error replies .h
//
