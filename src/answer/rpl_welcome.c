#include "irc.h"

void		rpl_welcome(t_answer *answer, char *buf_stdin, t_prompt *prompt)
{
	char	buf[1024];
	t_list	*elem;

	ft_bzero(buf, 1024);
	ft_strcat(buf, "Welcome to the Internet Relay Network ");
	if ((elem = ft_lst_at(answer->params, 3)))
		ft_strcat(buf, (char *)elem->content);
	ft_strcat(buf, "!");
	if ((elem = ft_lst_at(answer->params, 4)))
		ft_strcat(buf, (char *)elem->content);
	ft_strcat(buf, "@");
	if ((elem = ft_lst_at(answer->params, 5)))
		ft_strcat(buf, (char *)elem->content);
	prompt_push(prompt, buf_stdin, buf);
}
