/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:47:31 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 20:47:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void	usage(char *str)
{
	printf("usage %s <addr> <port>\n", str);
	exit(-1);
}

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
	int				port;
	int				sock;
	int				c;
	int				nread;
	char			buf[1024];
	
	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);	
	sock = gen_client(av[1], port);
	c = '\0';
	ft_bzero(buf, 1024);
	while (1)
	{
		read(0, &c, 1);
		write(sock, &c, 1);
		nread = read(sock, buf, 1024);
		if (nread > 0)
			write(1, buf, 1024);
	}
	close(sock);
	return (0);
}
