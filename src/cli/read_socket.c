#include "irc.h"

void		read_socket(char buf_stdin[], char buf_socket[],
		int sock, t_prompt *prompt)
{
	char		buf[512 + 1];
	t_answer	answer;

	(void)sock;
	DG("read socket");
	ft_bzero(buf, 512);
	recv(sock, buf, 512, 23);
	DG("reply %s", buf);	
	while (1);
	ft_strcat(buf_socket, buf);
	answer_init(&answer);
	parse_bufsocket(buf_socket, &answer);
	if (answer.reply)
	{
		DG("answer execute");
		answer_execute(&answer, buf_stdin, prompt);
		ft_bzero(buf_socket, 1024);
		//buffer circulaire
	}
	answer_destroy(&answer);
}
