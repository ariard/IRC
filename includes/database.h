/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:33:43 by ariard            #+#    #+#             */
/*   Updated: 2017/06/23 17:29:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_H
#define DATABASE_H

#include "irc.h"

struct s_client
{
	char	*uid;
	char	*server;
	int	socket;
	char	type;
	char	*wrbuf;
	int	wrindex;
	char	*rdbuf;
	int	rdindex;
	char	password[31];
	char	*local_name;
};

struct s_user
{
	char	nickname[10];
	char	*username;
	char	*hostname;
	char	*servername;
	char	*realname;
	int	mode;
	char	*local_uid;
};

struct s_channel
{
	char	name[51];
	t_list	*members;
	int	mode;
	int	scope;
};

void	client_init(t_client *client, int clifd, char *servername);

int	client_cmp(const void *content1, const void *content2);

int	client_print(void *content);

void	client_destroy(void *content, size_t content_size);

void	user_init(t_user *user, char *msg, char *uid);

int	user_cmp(const void *content, const void *key);


#endif
