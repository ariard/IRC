#include "irc.h"

void	user_init(t_user *user, char *nickname)
{
	ft_strncpy(user->nickname, nickname, 9);
	user->username = NULL;
	user->hostname = NULL;
	user->servername = NULL;
	user->realname = NULL;
	user->mode = 0;
	user->local_uid = 0;
}
