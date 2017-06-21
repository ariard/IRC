#include "irc.h"

void	init_serv(char *name, t_server *server)
{
	if (ft_strlen(name) > 63)
		ft_usage("ircd: servername is too long, max 63 characters");
	ft_bzero(server->name, 63);
	ft_strcpy(server->name, name);
	hashtab_init(&server->clients, 200, &ft_hash_string);
	hashtab_init(&server->channels, 200, &ft_hash_string);
	hashtab_init(&server->servers, 200, &ft_hash_string);
}
