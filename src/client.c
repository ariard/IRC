#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void	usage(char *str)
{
	printf("usage %s <addr> <port>\n", str);
	exit(-1);
}

int		create_client(char *addr, int port)
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
	int						port;
	int						sock;
	
	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);	
	sock = create_client(av[1], port);
	write(sock, "bonjour\n", 8);
	close(sock);
	return (0);
}
