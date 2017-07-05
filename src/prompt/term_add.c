#include "irc.h"

void		term_right(int size)
{
	while (size--)
		tputs(tgetstr("nd", NULL), 0, &term_put);
}
