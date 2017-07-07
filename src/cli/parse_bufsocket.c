#include "irc.h"

void		parse_bufsocket(char *buf, t_answer *answer)
{
	int	i;
	char	**msg;

	i = -1;
	while (buf[++i])
	{
		if (i != 0 && buf[i] == 10 && buf[i - 1] == 13)
		{
			msg = ft_split_whitespaces(buf);						
			if (msg[1])
				answer->reply = ft_strdup(msg[1]);
			i = -1;
			while (msg[2] && msg[++i])
				ft_lsteadd(&answer->params, ft_lstnew(&msg[i], ft_strlen(msg[i])));
			ft_sstrfree(msg);
		}
	}
	DG("end parse");
}
