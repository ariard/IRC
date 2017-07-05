#include "irc.h"

int		term_put(int c)
{
	write(1, &c, 1);
	return (1);
}
