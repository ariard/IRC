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

/* Class of Users */

# define REGULAR	1 << 0
# define OPERATOR	1 << 1
# define SERVICE	1 << 2


/* Server side */

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
	int		uid;
	char	*server;
	char	type;
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
//	servers topos
};

typedef struct s_server			t_server;

int		daemonize(void);

void	server_loop(int dest, int s_sock);

void	init_serv(char *name, t_server *server);



#endif


// grammar parsing .h
// error replies .h
//
