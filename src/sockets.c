/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:06:32 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 17:13:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		accept_cli(fd_set *allset, int s_sock, int *maxfd, t_server *server)
{	
	int						clifd;
	unsigned int			len;
	struct sockaddr_in		csin;	
	t_client				client;

	if ((clifd = accept(s_sock, (struct sockaddr *)&csin, &len)) < 0)
		ft_usage("accept error");
	client_init(&client, clifd);
	hashtab_insert(&server->clients, ft_lstnew(&client, sizeof(client)), 
		client.username, &client_cmp);
	FD_SET(client.socket, allset);
	if (client.socket > *maxfd)
		*maxfd = client.socket;
}

void		read_sockets(fd_set *rset, fd_set *allset, t_server *server)
{
	int				nread;
	char			buf[1024];
	t_client		client;

	while ((client = hashtab_generator(server->clients)))
	{
		if (FD_ISSET(client.socket, &rset))
		{
			ft_bzero(buf, 1024);
			if ((nread = read(client.socket, buf, 1024)) < 0)
				ft_usage("write error");
			else if (nread == 0)
			{
				DG("client closed");
				FD_CLR(client.socket, allset);
				close(client.socket);
			}
			else
				write(dest, buf, nread);
		}
	}
}
		
void		manage_sockets(int dest, int s_sock, int *maxfd, fd_set *allset, t_server *server)
{
	fd_set	rset;

	rset = *allset;
	if ((select(maxfd + 1, rset, NULL, NULL, NULL)) < 0)
		ft_usage("select error");
	if (FD_ISSET(s_sock, &rset))
		accept_cli(&rset, allset, &maxfd, s_sock, server);
	else
		read_sockets(dest, &rset, allset, server);
}
