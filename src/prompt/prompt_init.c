#include "irc.h"

void	prompt_init(t_prompt *prompt)
{
	struct winsize	w;	

	ioctl(0, TIOCGWINSZ, &w);
	prompt->col = w.ws_col;
	prompt->row = w.ws_row;
	prompt->prompt = ft_strdup("<default> ");
	prompt->len = ft_strlen(prompt->prompt);
	prompt->cursor.x = prompt->len + 1;
	prompt->cursor.y = 0;
	term_newline(2);
	term_insert(prompt->prompt);
}
