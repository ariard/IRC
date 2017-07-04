#include "irc.h"

void		cmd_user(t_cmd *cmd, t_server *server)
{
	t_user	*user;
	t_list	*elem;
	
	DG("in USER");
	elem = hashtab_lookup(&server->clients, cmd->uid, &client_cmp);
	DG("here");
	if (elem && !(elem = hashtab_lookup(&server->users, 
		(char *)((t_client *)elem->content)->local_name, &user_cmp)) && !elem)
		return (construct_msg(cmd->uid, server, ERR_REGISTERORDER));
	DG("here 2");
	if ((user = (t_user *)elem->content) && user->username)
		return (construct_msg(cmd->uid, server, ERR_ALREADYREGISTERED));
	if (ft_lst_at(cmd->params, 0) && ft_lst_at(cmd->params, 1)
		&& ft_lst_at(cmd->params, 3))
	{
		user->username = ft_strdup((char *)((t_list *)ft_lst_at(cmd->params, 0))->content);
		user->realname = ft_strdup((char *)((t_list *)ft_lst_at(cmd->params, 3))->content);
		user->mode = ft_atoi((char *)((t_list *)ft_lst_at(cmd->params, 2))->content);
		DG("username %s", user->username);
		DG("realname %s", user->realname);
		DG("mode %d", user->mode);
	}	
	else
	{
		return (construct_msg(cmd->uid, server, ERR_NEEDMOREPARAMS));
	}
}
