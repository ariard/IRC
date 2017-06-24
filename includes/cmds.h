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

# define NOSPCRLFCL	1 << 0
# define SPACE		1 << 1
# define COLON		1 << 2
# define AT_SIGN	1 << 3 
# define EXCLAMATION	1 << 4

struct s_lexmatch
{
	int	type;
	char	min
	char	max;
}

typedef struct s_lexmatch	t_lexmatch;

struct s_token
{
	int	type;
	char	value;
};

typedef struct s_token		t_token;

struct s_cmd
{
	char	*prefix;
	char	*cmd;
	t_list	*params;
};

typedef struct s_cmd		t_cmd;

void	lexer(t_list tokens, int content);

void	parse(t_list *tokens);

#endif
