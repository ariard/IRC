#include "irc.h"

static t_ansmatch	g_ansmatch[] = 
{
	{"001", &rpl_welcome},
};

void		answer_execute(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	int	i;

	i = -1;
	while (ft_strcmp(g_ansmatch[++i].id, answer->reply));
	g_ansmatch[i].f(answer, buf_stdin, prompt);
}
