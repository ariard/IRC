/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:11:24 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 20:29:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void		manage_cmds(t_server *server)
{
	t_cmd	cmd;
	t_list	*tokens;

	if (!server->cmds && server->cmds->content)
		return ; 
	tokens = NULL;
	cmd.uid = (char *)((t_streamcmd *)(server->cmds)->content)->uid;
	lexer(&tokens, ft_lst_pop(&server->cmds));
	if (parse(&tokens, &cmd))
		DG("ERROR");
	print_cmd(&cmd, NULL);
	execute_cmd(&cmd, server);
//	ft_lstiter(server->cmds, &print_cmds, NULL);
}
