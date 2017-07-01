#include "irc.h"

void	cmd_destroy(void *content, size_t size)
{
	char	*str;

	(void)size;
	str = (char *)content;
	ft_strdel(&str);
}	
