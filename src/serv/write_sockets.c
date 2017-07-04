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

	hashtab_iterator(&server->clients, 1);
	while ((elem = hashtab_iterator(&server->clients, 0)))
	{
		client = (t_client *)elem->content;
//		DG("writing client socket is %d", client->socket);
		if (FD_ISSET(client->socket, wset) && ft_strlen(client->wrbuf))
		{
			if ((nread = write(client->socket, client->wrbuf,
				ft_strlen(client->wrbuf))) < 0)
				ft_usage("write client error");
			else if (nread == 0)
			{
				DG("client closed");
				FD_CLR(client->socket, allset);
				close(client->socket);
			}
			ft_bzero(client->wrbuf, ft_strlen(client->wrbuf));
			client->wrindex = 0;
		}
	}
}
