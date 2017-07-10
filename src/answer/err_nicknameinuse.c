#include "irc.h"

void		err_nicknameinuse(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	char	buf[1024];
	t_list	*elem;

	ft_bzero(buf, 1024);
	if ((elem = ft_lst_at(answer->params, 3)))
		ft_strcat(buf, (char *)elem->content);
	ft_strcat(buf, ":Nickname is already in use");
	prompt_push(prompt, buf_stdin, buf);
}
