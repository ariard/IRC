/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:23:36 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 21:38:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		accept_cli(fd_set *allset, int s_sock, int *maxfd, t_server *server)
{	
	int						clifd;
	unsigned int			len;
	struct sockaddr_in		csin;	
	t_client				client;

	len = sizeof(struct sockaddr_in);
	if ((clifd = accept(s_sock, (struct sockaddr *)&csin, &len)) < 0)
		ft_usage("accept error");
	client_init(&client, clifd, server->name);
	hashtab_insert(&server->clients, ft_lstnew(&client, sizeof(client)), 
		client.uid, &client_cmp);
	FD_SET(client.socket, allset);
	if (client.socket > *maxfd)
		*maxfd = client.socket;
	DG("NEW CLIENT %s", client.uid);
}
