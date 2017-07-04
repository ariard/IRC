#include "irc.h"

int	user_cmp(const void *content, const void *key)
{
	if (!content)
		return (1);
	if (!ft_strcmp(((t_user *)content)->nickname, key))
		return (0);
	return (1);
}
