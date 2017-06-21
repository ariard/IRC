/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cient_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 19:18:43 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 19:27:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int		client_print(void *content)
{
	t_client	*client;

	client = (t_client *)content;
	DG("client name %s", client->uid);
	DG("client socket %d", client->socket);
	return (0);
}
