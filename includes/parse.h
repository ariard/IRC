/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:34:23 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 19:00:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
#define PARSE_H

# include "irc.h"

enum	e_sym
{
	TERM = 0,
	NOSPCRLFCL,
	SPACE,
	COLON,
	AT_SIGN,
	EXCLAMATION,
	PREFIX,
	SPACE_PREFIX,
	CMD,
	PARAM,
	ERROR,
};

struct s_lexmatch
{
	int	type;
	char	min;
	char	max;
};


struct s_parsematch
{
	int	sym;
	int	top;
	int	newtype;
};


struct s_token
{
	int	type;
	char	*value;
};


struct s_cmd
{
	char 	*uid;
	char	*prefix;
	char	*cmd;
	t_list	*params;
};

void	lexer(t_list **tokens, t_list *top);

int	parse(t_list **tokens, t_cmd *cmd);

void	get_cmd_members(t_list **stack, t_cmd *cmd);

void	token_destroy(void *content, size_t size);

void	cmd_destroy(void *content, size_t size);

#endif
