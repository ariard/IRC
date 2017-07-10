/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sockets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:21:34 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 18:27:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		read_sockets(fd_set *rset, fd_set *allset, t_server *server, int dest)
{
	int				nread;
	t_list			*elem;
	t_client		*client;

	(void)dest;
	hashtab_iterator(&server->clients, 1);
	while ((elem = hashtab_iterator(&server->clients, 0)))
	{
		client = (t_client *)elem->content;
		if (FD_ISSET(client->socket, rset))
		{
			DG("client uid is %s", client->uid);
			if ((nread = cirbuf_read(client->socket, client->rdbuf, 513,
				&client->rdindex)) < 0)
				DG("read error");
			else if (nread == 0)
			{
				DG("CLOSED %s", client->uid);
				FD_CLR(client->socket, allset);
				hashtab_del(&server->clients, client->uid, 
					&client_cmp, &client_destroy);
			}
			else
			{
//				write(dest, buf, nread);
				DG("rd: %s", client->rdbuf);
				DG("id : %d", client->rdindex);
				first_parse(client->rdbuf, client->rdindex, server,
					client->uid);
			}
		}
	}
}
