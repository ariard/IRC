/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bucket.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:19:04 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 22:34:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int		print_bucket(void *content, void *data)
{
	(void)data;
	DG("bucket %d, is %p", *(int *)data, (t_list *)content);
	return (0);
}	
