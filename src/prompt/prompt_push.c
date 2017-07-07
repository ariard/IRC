#include "irc.h"

void		prompt_push(t_prompt *prompt, char *bufstdin, char *buf)
{
	term_del(ft_strlen(prompt->prompt) + ft_strlen(bufstdin));
	term_up(2);
	term_insert(prompt->prompt);	
	term_insert(buf);
	term_newline(2);
	term_insert(prompt->prompt);
	prompt->cursor.x = ft_strlen(prompt->prompt) + 1;
	prompt->cursor.y = 0;
}
