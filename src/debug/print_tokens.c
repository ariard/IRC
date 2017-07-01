#include "irc.h"

int		print_tokens(void *content, void *data)
{
	t_token		*token;

	(void)data;
	token = (t_token *)content;
	if (token->type == NOSPCRLFCL)
		DG("NOSPCRLFCL %s", token->value);
	if (token->type == SPACE)
		DG("SPACE sp");
	if (token->type == COLON)
		DG("COLON %s", token->value);
	if (token->type == AT_SIGN)
		DG("AT SIGN  %s", token->value);
	if (token->type == EXCLAMATION)
		DG("EXCLAMATION  %s", token->value);
	if (token->type == TERM)
		DG("TERM null");
	if (token->type == PREFIX)
		DG("PREFIX %s", token->value);
	if (token->type == CMD)
		DG("CMD %s", token->value);
	if (token->type == PARAM)
		DG("PARAM %s", token->value);
	return (0);
}
