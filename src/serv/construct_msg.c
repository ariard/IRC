#include "irc.h"

void		construct_msg(char *uid, t_server *server, ...)
{
	t_list		*elem;
	t_client	*client;
	va_list		ap;
	char		*s;
	int		size;

	if (!(elem = hashtab_lookup(&server->clients, uid, &client_cmp)))
		return ;
	client = (t_client *)elem->content;
	va_start(ap, server);
	ft_strncat(client->wrbuf, ":", 1);
	ft_strncat(client->wrbuf, server->name, ft_strlen(server->name));
	ft_strncat(client->wrbuf, " ", 1);
	s = va_arg(ap, char *);
	ft_strncat(client->wrbuf, s, 3);
	ft_strncat(client->wrbuf, " " , 1);
	ft_strncat(client->wrbuf, client->local_name, ft_strlen(client->local_name));
	client->wrindex += 8 + ft_strlen(server->name) + ft_strlen(client->local_name);
	size = va_arg(ap, int);
	while (size-- && (s = va_arg(ap, char *))) 
	{
		ft_strncat(client->wrbuf, " ", 1);
		ft_strncat(client->wrbuf, s, ft_strlen(s));
		client->wrindex += ft_strlen(s) + 1;		
	}
	va_end(ap);
	ft_strncat(client->wrbuf, "\r\n", 2);
	DG("retour buf : %s", client->wrbuf);
}
