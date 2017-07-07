/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:06:32 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 22:45:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		manage_sockets(int dest, int s_sock, int *maxfd, fd_set *allset, 
		t_server *server)
{
	fd_set		rset;
	fd_set		wset;

	rset = *allset;
	wset = *allset;
	(void)dest;
	if ((select((*maxfd + 1), &rset, &wset, NULL, NULL)) < 0)
		DG("select error");
	if (FD_ISSET(s_sock, &rset))
		accept_cli(allset, s_sock, maxfd, server);
	else
	{
		read_sockets(&rset, allset, server, dest);
		write_sockets(&wset, allset, server);
	}
}
