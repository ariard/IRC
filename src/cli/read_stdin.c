#include "irc.h"

static t_keymatch	g_keymatch[] = 
{
	{CR, &send_buf},
	{DFLT, &add_buf},
};

void	read_stdin(char buf[], t_prompt *prompt, int sock)
{
	int	key;
	int	i;

	(void)buf;
	(void)prompt;
	(void)sock;
	(void)g_keymatch;
	while (1)
	{
		key = 0;
		if (read(0, &key, 1) <= 0)
			break;
		i = -1;
//		DG("key %c", key);
		while (g_keymatch[++i].key != DFLT && g_keymatch[i].key != key);
		g_keymatch[i].f(buf, prompt, key, sock);
	}
}
