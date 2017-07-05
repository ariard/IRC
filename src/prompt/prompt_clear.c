#include "irc.h"

void		prompt_clear(t_prompt *prompt)
{
	term_del(prompt->cursor.x);
	prompt->cursor.x = prompt->len + 1;
}
