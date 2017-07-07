/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sockets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:20:52 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 17:40:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		write_sockets(fd_set *wset, fd_set *allset, t_server *server)
{
	int			nread;
	t_list		*elem;
	t_client	*client;
//	static int	i;

	hashtab_iterator(&server->clients, 1);
	while ((elem = hashtab_iterator(&server->clients, 0)))
	{
		client = (t_client *)elem->content;
		if (FD_ISSET(client->socket, wset) && ft_strlen(client->wrbuf))
		{
			DG("writing client socket is %d with %s", client->socket,
				client->wrbuf);
			if ((nread = send(client->socket, client->wrbuf,
				ft_strlen(client->wrbuf), 0)) < 0)
				DG("write client error");
			else if (nread == 0)
			{
				DG("client closed");
				FD_CLR(client->socket, allset);
				close(client->socket);
			}
			ft_bzero(client->wrbuf, ft_strlen(client->wrbuf));
			client->wrindex = 0;
		}
//		if (i++ < 10)	
//			ft_strcpy(client->wrbuf, "myteststring");
	}
}
