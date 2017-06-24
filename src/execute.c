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

void		execute_cmds(t_server *server)
{
	t_cmd	cmd;
	t_list	*tokens;

	tokens = NULL;
	lexer(tokens, pop(&server->cmds));
	parse(cmd);
	ft_lstiter(server->cmds, &print_cmds, NULL);
}
