/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:56:51 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 20:16:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		client_destroy(void *content, size_t content_size)
{
	t_client	*client;

	(void)content_size;
	client = (t_client *)content;
	ft_strdel(&client->uid);
	client->server = NULL;
	close(client->socket);
	client->socket = 0;
	client->type = 0;
	ft_strdel(&client->wrbuf);
	client->wrindex = 0;
	ft_strdel(&client->rdbuf);
	client->rdindex = 0;
}
