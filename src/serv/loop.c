/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:04:00 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 18:53:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void	server_loop(int dest, int s_sock, t_server *server)
{	
	fd_set	allset;
	int		maxfd;

	FD_ZERO(&allset);
	FD_SET(s_sock, &allset);
	maxfd = s_sock;
	while (1)
	{
		manage_sockets(dest, s_sock, &maxfd, &allset, server);
		manage_cmds(server);
	}
}
