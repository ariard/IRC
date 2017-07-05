#include "irc.h"

int		term_init(void)
{
	char	*tname;
	char	buf[2048 + 1];

	tname = getenv("TERM");
	if (!tname)
		return (0);
	return (tgetent(buf, tname));
}
