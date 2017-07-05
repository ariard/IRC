#include "irc.h"

void	term_newline(int size)
{
	while (size--)
	{
		tputs(tgetstr("do", NULL), 0, &term_put);
		tputs(tgetstr("cr", NULL), 0, &term_put);
	}
}
