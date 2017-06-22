/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:03:34 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 21:56:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int		client_cmp(const void *content, const void *key)
{
	if (!content)
		return (1);
	if (!ft_strcmp(((t_client *)content)->uid, key))
		return (0);
	return (1);
}
