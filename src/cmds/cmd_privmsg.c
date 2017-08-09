#include "irc.h"

static int	push_msg_all(t_list *rec, t_server *server, char *str, char *nickname)
{		
	t_list		*elem;
	t_user		*user;
	int		i;

	i = 0;
	DG("in push msg all");
	DG("str %s", str);
	while (rec && ft_lst_at(rec, 1))
	{
		DG("rec is %s", rec->content);
		if (!(elem = hashtab_lookup(&server->users, (char *)rec->content, &user_cmp)))
			i = 1;
		else	
		{
			user = (t_user *)elem->content;
			DG("gonna lookup");
			if ((elem = hashtab_lookup(&server->clients, user->local_uid, &client_cmp)))
			{
				DG("construct msg : %s", nickname);
				construct_msg(user->local_uid, server, RPL_MSG(nickname, str));
			}
			else
				i = 1;
		}
		if (ft_strcmp((char *)(ft_lst_at(rec, 1))->content, ",") != 0)
			break;
		rec = rec->next;
	}
	return (i);
}

void		cmd_privmsg(t_cmd *cmd, t_server *server)
{
	t_client	*client;
	t_list		*elem;
	int		i;
	char		*str;

	DG("in PRIVMSG");
	if ((elem = hashtab_lookup(&server->clients, cmd->uid, &client_cmp)))
		client = (t_client *)elem->content;
	if (!cmd->params)
		return (construct_msg(client->uid, server, ERR_NORECIPIENT(client->local_name, "/PRIVMSG")));
	i = 0;
	elem = cmd->params;
	while (elem && ft_lst_at(elem, 1) && ++i)
	{
		if (ft_strcmp((char *)(ft_lst_at(elem, 1))->content, ",") != 0)
			break;
		elem = ft_lst_at(elem, 1);
	}
	str = ft_lst2str(ft_lst_at(cmd->params, i));
	if (i >= 11)
		construct_msg(client->uid, server, ERR_TOOMANYTARGETS(client->local_name, "407", str));
	if (!elem)
		return (construct_msg(client->uid, server, ERR_NOTEXTOSEND(client->local_name)));
	if (i < 11)
		if (push_msg_all(cmd->params, server, str, client->local_name))
			broadcast();
	ft_strdel(&str);
}
