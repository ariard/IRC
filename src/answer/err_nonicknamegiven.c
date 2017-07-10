#include "irc.h"

void		err_nonicknamegiven(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	char	buf[1024];

	(void)answer;
	ft_bzero(buf, 1024);
	ft_strcat(buf, ":No nickname given");
	prompt_push(prompt, buf_stdin, buf);
}
