#include "irc.h"

void		construct_msg(char *uid, t_server *server, char *msg)
{
	t_list		*elem;
	t_client	*client;

	if (!(elem = hashtab_lookup(&server->clients, uid, &client_cmp)))
		return ;
	client = (t_client *)elem->content;
	ft_strncat(client->wrbuf, ":", 1);
	ft_strncat(client->wrbuf, server->name, ft_strlen(server->name));
	ft_strncat(client->wrbuf, " ", 1);
	ft_strncat(client->wrbuf, msg, 3);
	ft_strncat(client->wrbuf, " " , 1);
	ft_strncat(client->wrbuf, client->local_name, ft_strlen(client->local_name));
	ft_strncat(client->wrbuf, "\r\n", 2);
	client->wrindex += 8 + ft_strlen(server->name) + ft_strlen(client->local_name);
}
