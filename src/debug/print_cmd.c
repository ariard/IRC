#include "irc.h"

int	print_params(void *content, void *data)
{
	char	*str;

	(void)data;
	str = (char *)content;
	DG("param %s", str);
	return (0);
}

int		print_cmd(void *content, void *data)
{
	t_cmd		*cmd;
	
	(void)data;
	cmd = (t_cmd *)content;
	if (cmd->prefix)
		DG("prefix %s", cmd->prefix);
	if (cmd->cmd)
		DG("cmd %s", cmd->cmd);	
	if (cmd->params)
		ft_lstiter(cmd->params, &print_params, NULL);
	return (0);
}
