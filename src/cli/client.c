/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:47:31 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 17:28:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"


int		gen_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;	
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Client error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int ac, char **av)
{
	int			port;
	int			sock;
	int			i;
	char			buf[CLIBUF + 1];

	if (ac != 3)
		ft_usage("usage %s <addr> <port>\n", av[0]);
	port = atoi(av[2]);	
	sock = gen_client(av[1], port);
	configure_client(STDIN_FILENO);
	loop(sock);	
	while (1)
	{ 
		ft_bzero(buf, CLIBUF);
		i = 0;
		while (buf[i] != 13 || ++i < CLIBUF)
			read(0, buf, CLIBUF);
		ft_strncat(buf, "\n", 1);
		write(sock, buf, ft_strlen(buf));
	}
	close(sock);
	return (0);
}
