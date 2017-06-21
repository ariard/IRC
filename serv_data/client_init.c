/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:04:54 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 18:02:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		client_init(t_client *client, int clifd, char *servername)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	client->socket = clifd;	
	client->uid = ft_itoa(tp.tv_sec);
	client->server = servername;
	client->type = CLIENT;
}
