/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:11:10 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 16:27:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void	init_serv(char *name, t_server *server)
{
	if (ft_strlen(name) > 63)
		ft_usage("ircd: servername is too long, max 63 characters");
	ft_bzero(server->name, 63);
	ft_strcpy(server->name, name);
	DG("server name %s", server->name);
	hashtab_init(&server->clients, 200, &ft_hash_string);
	hashtab_init(&server->channels, 200, &ft_hash_string);
	hashtab_init(&server->servers, 200, &ft_hash_string);
	hashtab_init(&server->users, 200, &ft_hash_string);
	server->cmds = NULL;
}
