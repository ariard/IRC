#include "irc.h"

void		get_cmd_members(t_list **stack, t_cmd *cmd)
{
	t_token		*token;

	cmd->prefix = NULL;
	cmd->cmd = NULL;
	cmd->params = NULL;
	while (stack && *stack)
	{
		token = (*stack)->content;
		if (token->type == PREFIX)
			cmd->prefix = ft_strtrim(token->value);
		else if (token->type == CMD)
			cmd->cmd = ft_strtrim(token->value);
		else if (token->type == PARAM)
			ft_lstadd(&cmd->params, ft_lstnew(token->value, ft_strlen(token->value)));
		token_destroy((*stack)->content, 0);
		free(ft_lst_pop(stack));
	}
}
