/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:06:32 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 20:48:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		manage_sockets(int dest, int s_sock, int *maxfd, fd_set *allset, t_server *server)
{
	fd_set		rset;
	fd_set		wset;

	rset = *allset;
	wset = *allset;
	if ((select(*(maxfd + 1), &rset, &wset, NULL, NULL)) < 0)
		ft_usage("select error");
	if (FD_ISSET(s_sock, &rset))
		accept_cli(allset, s_sock, maxfd, server);
	else
	{
		read_sockets(&rset, allset, server, dest);
		write_sockets(&wset, allset, server);
	}
}
