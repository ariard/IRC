#include "irc.h"

void		token_destroy(void *content, size_t size)
{
	t_token	*token;

	(void)size;
	token = (t_token *)content;
	ft_strdel(&token->value);
	token->type = 0;
	free(token);
}
