/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:36:40 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 18:23:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		first_parse(char *buffer, int *index, t_server *server)
{
	int		i;

	(void)server;
	i = *index - 1;
	while (i > 0 && i != *index && buffer[i])
	{
		if (i != 0 && buffer[i] == 10 && buffer[i - 1] == 13)
			DG("delim detected");
		else if (buffer[i] == 10 && buffer[RDBUFSIZE] == 13)
			DG("delim detected");
		if (i == 0)
			i = RDBUFSIZE;
		i--;
	}
}
