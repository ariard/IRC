/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 18:56:25 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 20:20:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int			print_cmds(void *content, void *data)
{
	char	*str;

	(void)data;
	str = (char *)content;
	DG("cmds : [%s]", str);
	return (0);
}
