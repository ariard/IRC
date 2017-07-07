#include "irc.h"

void		term_up(int size)
{
	while (size--)
	{
		tputs(tgetstr("up", NULL), 0, &term_put);
		tputs(tgetstr("cr", NULL), 0, &term_put);
	}
}
