/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:36:40 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 20:31:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

static void		push_buf(int i, int index, char *bufcli,
			t_server *server,
			char *uid)
{
	int		j;
	char		buf[514];
	t_streamcmd	stream;


	(void)uid;
	DG("delim detect!");
	ft_bzero(buf, 514);
//	DG("size one %d", RDBUFSIZE - index);
	ft_memcpy(buf, &bufcli[index], RDBUFSIZE - index);
//	DG("size two %d", i);
	ft_memcpy(&buf[RDBUFSIZE - index + 1], &bufcli[0], i);
//	DG("nul is %d", i + RDBUFSIZE - index);
	buf[i + RDBUFSIZE - index + 1] = 0;
	ft_bzero(&bufcli[index], RDBUFSIZE - index);
	ft_bzero(bufcli, i + 1);
	j = -1;
	while (!buf[++j] && j < 514);
//	DG("new buf %s", &buf[j]);
	stream.buf = &buf[j];
	stream.uid = uid;
	ft_lsteadd(&server->cmds, ft_lstnew(&stream, sizeof(t_streamcmd *)));
}

void		first_parse(char *buffer, int index, t_server *server, char *uid)
{
	int		i;

	DG("in first parse %d", index);
	if (index > RDBUFSIZE || index < 0)
		DG("ERROR : read socket");
	(void)server;
	i = index - 1;
	while (i > 0 && i != index && buffer[i])
	{
		if (i != 0 && buffer[i] == 10 && buffer[i - 1] == 13)
			push_buf(i, index, buffer, server, uid);
		else if (buffer[i] == 10 && buffer[RDBUFSIZE - 1] == 13)
			push_buf(i, index, buffer, server, uid);
		if (i == 0)
			i = RDBUFSIZE;
		i--;
	}
	DG("after parse");
}
