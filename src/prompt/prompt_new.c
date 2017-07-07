#include "irc.h"

void		prompt_new(t_prompt *prompt)
{
	term_insert(prompt->prompt);
	prompt->cursor.x = prompt->len + 1;
}
