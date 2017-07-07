#include "irc.h"

void		term_insert(char *str)
{
	tputs(tgetstr("im", NULL), 0, &term_put);
	tputs(tgetstr("ic", NULL), 0, &term_put);
	tputs(str, 0, &term_put);
	tputs(tgetstr("ip", NULL), 0, &term_put);
	tputs(tgetstr("ei", NULL), 0, &term_put);
}
