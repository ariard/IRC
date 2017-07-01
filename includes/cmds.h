#ifndef IRC_H
#define IRC_H

#include "irc.h"

struct s_cmdmatch
{
	char	*name;
	void	(*func)(t_cmd *cmd, t_server *server);
}

typedef struct s_cmdmatch	t_cmdmatch;

void	cmd_pass(t_cmd *cmd, t_server *server);

void	cmd_nick(t_cmd *cmd, t_server *server);

void	cmd_user(t_cmd *cmd, t_server *server);

#endif
