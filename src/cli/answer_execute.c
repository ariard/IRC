#include "irc.h"

static t_ansmatch	g_ansmatch[] = 
{
	{"001", &rpl_welcome},
	{"431", &err_nonicknamegiven},
	{"432", &err_erroneusnickname},
	{"433", &err_nicknameinuse},
	{"461", &err_needmoreparams},
	{"462", &err_alreadyregistered},
	{"600", &err_lengpass},
	{"601", &err_registerorder},
	{NULL, NULL}
};

void		answer_execute(t_answer *answer, char *buf_stdin,
		t_prompt *prompt)
{
	int	i;

	i = -1;
	while (g_ansmatch[++i].id && ft_strcmp(g_ansmatch[i].id, answer->reply));
	if (g_ansmatch[i].f)
		g_ansmatch[i].f(answer, buf_stdin, prompt);
}
