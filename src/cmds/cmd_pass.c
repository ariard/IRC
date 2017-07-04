#include "irc.h"

void	cmd_pass(t_cmd *cmd, t_server *server)
{
	char		*pass;
	t_client	*client;
	t_list		*elem;

	DG("in PASS");
	if ((elem = hashtab_lookup(&server->clients, cmd->uid, &client_cmp)))
		client = (t_client *)elem->content;
	if (cmd->params)
		pass = (char *)(cmd->params)->content;
	else
		return (construct_msg(client->uid, server, ERR_NEEDMOREPARAMS)); 
	if (client->local_name)
		return (construct_msg(client->uid, server, ERR_ALREADYREGISTERED));
	if (ft_strlen(pass) > 30)
		return (construct_msg(client->uid, server, ERR_LENGPASS));
	else
		ft_strcpy(client->password, pass);
	DG("client pass : %s", client->password);
}
