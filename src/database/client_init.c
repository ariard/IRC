/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:04:54 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 16:27:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		client_init(t_client *client, int clifd, char *servername)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	client->uid = ft_itoa(tp.tv_sec);
	client->server = servername;
	client->socket = clifd;	
	client->type = CLIENT;
	client->wrbuf = ft_memalloc(sizeof(char) * 1024);
	client->wrindex = 0;
	client->rdbuf = ft_memalloc(sizeof(char) * RDBUFSIZE);
	client->rdindex = 0;
	client->user = NULL;
}
