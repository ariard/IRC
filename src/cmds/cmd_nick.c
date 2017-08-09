#include "irc.h"

void	cmd_nick(t_cmd *cmd, t_server *server)
{
	t_user		user;
	char		*local_nickname;
	char		*nickname;
	t_list		*elem;
	t_client	*client;
	
	if ((elem = hashtab_lookup(&server->clients, cmd->uid, &client_cmp)))
		local_nickname = (char *)((t_client *)elem->content)->local_name;
	if (!(char *)((t_client *)elem->content)->password)
		return (construct_msg(cmd->uid, server, ERR_REGISTERORDER("default")));
	if (cmd->params)
		nickname = (char *)(cmd->params)->content;
	else
		return (construct_msg(cmd->uid, server, ERR_NONICKNAMEGIVEN("default")));
	if (hashtab_lookup(&server->users, nickname, &user_cmp))
		return (construct_msg(cmd->uid, server, ERR_NICKNAMEINUSE("default")));
	if (ft_strlen(nickname) > 9)
		return (construct_msg(cmd->uid, server, ERR_ERRONEUSNICKNAME("default")));
	client = (t_client *)elem->content;
	client->local_name = nickname;
	if (!(elem = hashtab_lookup(&server->users, client->local_name, &user_cmp)))
	{
		user_init(&user, nickname, client->uid);
		hashtab_insert(&server->users, ft_lstnew(&user, sizeof(t_user)),
			nickname, user_cmp);
	}
	else if (elem->content)
		ft_strncpy(((t_user *)elem->content)->nickname, nickname, 9);
	DG("user nickanem %s", user.nickname);
}
//	ERR_UNAVAILRESOURCE
//	ERR_RESTRICTED
//	ERR_NICKCOLLISION
