#include "irc.h"

void		err_registerorder(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	char	buf[1024];

	(void)answer;
	ft_bzero(buf, 1024);
	ft_strcat(buf, ":You must respect register order : PASS - NICK - USER");
	prompt_push(prompt, buf_stdin, buf);
}
