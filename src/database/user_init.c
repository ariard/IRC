#include "irc.h"

void	user_init(t_user *user, char *nickname, char *uid)
{
	ft_strncpy(user->nickname, nickname, 9);
	user->username = NULL;
	user->hostname = NULL;
	user->servername = NULL;
	user->realname = NULL;
	user->mode = 0;
	user->local_uid = uid;
}
