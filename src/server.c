/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:18:43 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 19:35:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void	usage(char *str)
{
	printf("usage %s <port>\n", str);
	exit(-1);
}

int		gen_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int argc, char **argv)
{
	int			port;
	int			sock;
	int			fd;
	t_server	server;	

	if (argc < 2)
		ft_usage("ircd: port servername");
//	if (daemonize())
//		ft_usage("ircd: failed daemonization %d");
	init_serv(argv[2], &server);
	DG("daemonization successful : %d", getpid());
	port = ft_atoi(argv[1]);
	sock = gen_server(port);
	fd = open("/tmp/.irc_report", O_CREAT | O_WRONLY, 0644);
	server_loop(fd, sock, &server);
	close(sock);
	return (0);
}
