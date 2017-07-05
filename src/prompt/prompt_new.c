#include "irc.h"

void		prompt_new(t_prompt *prompt)
{
	term_newline(2);
	write(1, prompt->prompt, ft_strlen(prompt->prompt));
//	term_right(ft_strlen(prompt->prompt));
	prompt->cursor.x = prompt->len + 1;
}
