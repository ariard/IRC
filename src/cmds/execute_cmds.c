#include "irc.h"

static t_cmdmatch	g_cmdmatch[] = 
{
	{"PASS", &cmd_pass},
	{"NICK", &cmd_nick},
	{"USER", &cmd_user},
	{NULL, NULL},
};

void		execute_cmd(t_cmd *cmd, t_server *server)
{
	int	i;

	i = -1;
	while (g_cmdmatch[++i].name)
	{
		DG("[%s] vs [%s]", g_cmdmatch[i].name, cmd->cmd);
		if (!ft_strcmp(g_cmdmatch[i].name, cmd->cmd))
			return (g_cmdmatch[i].func(cmd, server));
	}
}
