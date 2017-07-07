#include "irc.h"

void		send_buf(char buf[], t_prompt *prompt, int key, int sock)
{
	(void)key;
	ft_strncat(buf, "\r\n", 2);
	write(sock, buf, ft_strlen(buf));
	prompt_push(prompt, buf, buf);
	ft_bzero(buf, CLIBUF);
}
