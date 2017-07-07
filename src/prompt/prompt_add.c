#include "irc.h"

void		prompt_add(t_prompt *prompt, char *buf)
{
	term_insert(buf);
	prompt->cursor.x += 1;
}
