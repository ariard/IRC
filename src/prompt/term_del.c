#include "irc.h"

void		term_del(int size)
{
	while (size--)
	{
		tputs(tgetstr("dm", NULL), 0, &term_put);
		tputs(tgetstr("dc", NULL), 0, &term_put);
		tputs(tgetstr("ed", NULL), 0, &term_put);
	}
}
