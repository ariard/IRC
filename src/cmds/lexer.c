#include "irc.h"

static t_lexmatch	g_lexmatch[] =
{
	{NOSPCRLFCL, 0x01, 0x09},
	{NOSPCRLFCL, 0x0B, 0x0C},
	{NOSPCRLFCL, 0x0E, 0x1F},
	{NOSPCRLFCL, 0x21, 0x39},
	{NOSPCRLFCL, 0x3B, 0x7F},
	{SPACE, 0x20, 0x20},
	{COLON, 0x3a, 0x3a},
	{AT_SIGN, 0x40, 0x40},
	{EXCLAMATION, 0x21, 0x21},
	{0, 0x0, 0x0},
};

void			lexer(t_list **tokens, t_list *top)
{
	int		i;
	char		*cmd;
	t_token		token;

	cmd = (char *)top->content;
	while (*cmd)
	{
		i = -1;
		DG("chr %c", *cmd);
		while (g_lexmatch[++i].type)
			if (*cmd >= g_lexmatch[i].min 
				&& *cmd <= g_lexmatch[i].max)
			{
				DG(" add token");
				token.type = g_lexmatch[i].type;
				token.value = ft_strndup(cmd, 1);
				ft_lsteadd(tokens, 
					ft_lstnew(&token, sizeof(token)));
			}
		cmd++;
	}
	ft_lstdelone(&top, &cmd_destroy);
}
