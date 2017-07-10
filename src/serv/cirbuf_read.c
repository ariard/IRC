/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:18:47 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 19:48:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int			cirbuf_read(int fd, char *cirbuf, int size, int *index)
{
	char	buf[size + 1];
	int		nread;

	nread = read(fd, buf, 1024);
	DG("nread is %d", nread);
	if (nread + *index >= RDBUFSIZE)
	{
		ft_memcpy(&cirbuf[*index], buf, RDBUFSIZE - *index);
		ft_memcpy(&cirbuf[0], &buf[RDBUFSIZE - *index],
			nread - (RDBUFSIZE - *index));
		*index = 0 + (nread - (RDBUFSIZE - *index));
	}
	else if (nread > 0)
	{
		ft_memcpy(&cirbuf[*index], buf, nread);
		DG("in cirbuf, id %d", *index);
		*index += nread;
		DG("in cirbuf, id %d", *index);
	}
	return (nread);
}
