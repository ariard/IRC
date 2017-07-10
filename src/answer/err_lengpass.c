#include "irc.h"

void		err_lengpass(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	char	buf[1024];

	(void)answer;
	ft_bzero(buf, 1024);
	ft_strcat(buf, "Password is max 31 char");
	prompt_push(prompt, buf_stdin, buf);
}
