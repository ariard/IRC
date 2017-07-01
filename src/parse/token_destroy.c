#include "irc.h"

void		token_destroy(void *content, size_t size)
{
	t_token	*token;

	(void)size;
	token = (t_token *)content;
	token->type = 0;
	ft_strdel(&token->value);
}
