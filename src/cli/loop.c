#include "irc.h"

void	cli_loop(int sock)
{
	char		buf_stdin[CLIBUF + 1];
	char		buf_socket[1024 + 1];
	t_prompt	prompt;

	prompt_init(&prompt);
	prompt_new(&prompt);
	while (1)
	{ 
		read_stdin(buf_stdin, &prompt, sock);
		read_socket(buf_stdin, buf_socket, &prompt);
	}
	// prompt_destroy
	// imprimer la ligne envoye
}
