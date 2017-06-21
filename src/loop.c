/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:04:00 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 17:04:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

/*int		serv_accept(int s_sock)
{
	int					cs;
	unsigned int		len;
	struct sockaddr_in	csin;

	len = sizeof(csin);
	cs = accept(s_sock, (struct sockaddr *)&csin, &len);
	return (cs);
}	
	
void	server_loop(int dest, int s_sock)
{
	fd_set	allset;
	fd_set	rset;
	char	buf[1024];
	int		clifd;
	int		nread;
	int		maxfd;
	int		maxi;
	int		i;
	int		n;
	int		client[1024];
	int		index;

	FD_ZERO(&allset);
	FD_SET(s_sock, &allset);
	maxfd = s_sock;
	maxi = -1;
	ft_bzero(client, 1024);
	index = 0;

	DG("loop");
	while (1)
	{
		rset = allset;
		if ((n = select(maxfd + 1, &rset, NULL, NULL, NULL)) < 0)
			write(dest, "select error", 12);
		if (FD_ISSET(s_sock, &rset))
		{
			DG("incoming connection");
			if ((clifd = serv_accept(s_sock)) < 0)
				write(dest, "server accept error", 18);
			client[index] = clifd;
			i = index++;
			FD_SET(clifd, &allset);
			if (clifd > maxfd)
				maxfd = clifd;
			if (i > maxi)
				maxi = i;
			continue;
		}
		i = -1;
		while (++i <= maxi)
		{
			if ((clifd = client[i]) < 0)
				continue;
			if (FD_ISSET(clifd, &rset))
			{
				ft_bzero(buf, 1024);
				if ((nread = read(clifd, buf, 1024)) < 0)
					write(dest, "read error on fd", 16);
				else if (nread == 0)
				{
					write(dest, "client closed", 13);
					FD_CLR(clifd, &allset);
					close(clifd);
				}
				else
					write(dest, buf, nread);
			}
		}
	}
}*/

void	server_loop(int dest, int s_sock, t_server *server)
{	
	fd_set	allset;
	int		maxfd;

	FD_ZERO(&allset);
	FD_SET(s_sock, &allset);
	index = 0;
	maxfd = s_sock;
	while (1)
	{
		manage_sockets(dest, s_sock, &maxfd, &allset, server);
		execute_cmds();
	}
}
