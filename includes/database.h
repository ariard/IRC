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

struct s_client
{
	char	*uid;
	char	*server;
	int		socket;
	char	type;
	char	*wrbuf;
	int		wrindex;
	char	*rdbuf;
	int		rdindex;
};

typedef struct s_client			t_client;

void	client_init(t_client *client, int clifd, char *servername);

int	client_cmp(const void *content1, const void *content2);

int	client_print(void *content);

void	client_destroy(void *content, size_t content_size);

void	cmd_destroy(void *content, size_t size);

#endif
