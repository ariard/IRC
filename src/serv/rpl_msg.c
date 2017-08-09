#include "irc.h"

void		rpl_msg(t_answer *answer, char *buf_stdin, t_prompt *prompt)
{
	char	buf[1024];
	t_list	*elem;
	int	i;

	ft_bzero(buf, 1024);
	if ((elem = ft_lst_at(answer->params, 3)))
		ft_strcat(buf, (char *)elem->content);
	ft_strcat(buf, " : ");
	i = 3;
	while (++i)
	{		
		if ((elem = ft_lst_at(answer->params, i)))
		{
			ft_strcat(buf, (char *)elem->content);
			ft_strcat(buf, " ");
		}
		else
			break;
	}
	prompt_push(prompt, buf_stdin, buf);
}
