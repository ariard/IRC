#include "irc.h"

void		parse_bufsocket(char *buf, t_answer *answer)
{
	int	i;
	int	j;
	char	**msg;

	i = -1;
	DG("buf %s", buf);
	while (buf[++i])
	{
		if (i != 0 && buf[i] == 10 && buf[i - 1] == 13)
		{
			msg = ft_split_whitespaces(buf);						
			if (msg[1])
				answer->reply = ft_strdup(msg[1]);
			j = -1;
			while (msg[2] && msg[++j])
				ft_lsteadd(&answer->params, ft_lstnew(msg[j], ft_strlen(msg[j])));
			ft_sstrfree(msg);
		}
	}
}
