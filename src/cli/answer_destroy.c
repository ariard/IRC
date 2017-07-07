#include "irc.h"

static void	answer_del(void *content, size_t size)
{
	(void)size;
	ft_strdel((char **)&content);
}

void		answer_destroy(t_answer *answer)
{
	answer->reply = NULL;
	ft_lstdel(&answer->params, &answer_del);
}
