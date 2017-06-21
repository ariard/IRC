/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sockets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:21:34 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 20:30:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		read_sockets(fd_set *rset, fd_set *allset, t_server *server, int dest)
{
	int				nread;
	char			buf[1024];
	t_list			*elem;
	t_client		*client;

	hashtab_generator(&server->clients, 1);
	while ((elem = hashtab_generator(&server->clients, 0)))
	{
		client = (t_client *)elem->content;
		DG("reading client socket is %d", client->socket);
		if (FD_ISSET(client->socket, rset))
		{
			ft_bzero(buf, 1024);
			if ((nread = read(client->socket, buf, 1024)) < 0)
				ft_usage("read client error");
			else if (nread == 0)
			{
				DG("client closed");
				FD_CLR(client->socket, allset);
				close(client->socket);
			}
			else
				write(dest, buf, nread);
		}
	}
}
