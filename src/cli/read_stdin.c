#include "irc.h"

static t_keymatch	g_keymatch[] = 
{
	{CR, &send_buf},
	{DFLT, &add_buf},
};

void	read_stdin(char buf[], int sock, t_prompt *prompt)
{
	char	b[514 + 1];
	int	i;
	int	j;

//	DG("read stdin");
	ft_bzero(b, 514);
	read(0, b, 514);
	j = -1;
	while (b[++j])
	{
		i = -1;
		while (g_keymatch[++i].key != DFLT && g_keymatch[i].key != b[j]);
		g_keymatch[i].f(buf, prompt, b[j], sock);
	}
//	DG("end read stdin");
}
