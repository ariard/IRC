#include "irc.h"

void	cli_loop(int sock)
{
	fd_set			allset;
	int			maxfd;
	char			buf_stdin[CLIBUF + 1];
	char			buf_socket[1024 + 1];
	t_prompt		prompt;

	prompt_init(&prompt);
	ft_bzero(buf_stdin, CLIBUF);
	ft_bzero(buf_socket, 1024);
	maxfd = sock;
	while (1)
	{
		FD_ZERO(&allset);
		FD_SET(sock, &allset);
		FD_SET(0, &allset);
		if ((select(maxfd + 1, &allset, NULL, NULL, NULL)) < 0)
			DG("select error");
		if (FD_ISSET(0, &allset))
			read_stdin(buf_stdin, sock, &prompt);
		if (FD_ISSET(sock, &allset))
			read_socket(buf_stdin, buf_socket, sock, &prompt);
		FD_CLR(0, &allset);
		FD_CLR(sock, &allset);
	}
}
