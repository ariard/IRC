#include "irc.h"

void		err_alreadyregistered(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	char	buf[1024];

	(void)answer;
	ft_bzero(buf, 1024);
	ft_strcat(buf, ":Unauthorized command (already registered)");
	prompt_push(prompt, buf_stdin, buf);
}
