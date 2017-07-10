#ifndef CMDS_H
#define CMDS_H

#include "irc.h"

struct s_cmdmatch
{
	char	*name;
	void	(*func)(t_cmd *cmd, t_server *server);
};

void	cmd_pass(t_cmd *cmd, t_server *server);

void	cmd_nick(t_cmd *cmd, t_server *server);

void	cmd_user(t_cmd *cmd, t_server *server);

void	cmd_quit(t_cmd *cmd, t_server *server);

void	cmd_privmsg(t_cmd *cmd, t_server *server);

#endif
