/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:03:34 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 18:07:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int		client_cmp(void *content1, void *content2)
{
	if (!ft_strcmp(((t_client *)content1)->uid, ((t_client *)content2)->uid))
		return (0);
	return (1);
}
