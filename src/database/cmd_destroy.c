#include "irc.h"

void	cmd_destroy(void *content, size_t size)
{
	t_streamcmd	*cmd;

	(void)size;
	cmd = (t_streamcmd *)content;;
	ft_strdel(cmd.buf);
	cmd.uid = NULL;
}	
