#include "irc.h"

void		prompt_add(t_prompt *prompt)
{
//	term_right(1);
	prompt->cursor.x += 1;
}

//term insert
