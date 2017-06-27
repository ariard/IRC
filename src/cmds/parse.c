#include "irc.h"

static t_parsematch	g_parsematch[] =
{
	{NOSPCRLFCL, TERM, PROTO_PREFIX},
	{NOSPCRLFCL, PROTO_PREFIX, PROTO_PREFIX}
	{SPACE, PROTO_PREFIX, PREFIX},
};

void		init_stack(t_list *stack)
{
	t_cmd	cmd;

	cmd.type = TERM;
	cmd.value = 0;
	ft_lstadd(&stack, ft_lstnew(&cmd, sizeof(cmd)));
}

void		shift(int newtype, t_list **stack, t_list **tokens)
{
	t_token		*sym;

	if (!stack || !*stack || !tokens || !*tokens)
		return ; 
	sym = (**stack)->content;
	sym->type = newtype;
//	aggregate one ft_strncat
	ft_lstadd(stack, *tokens);
	*tokens = tokens->next;
}

void		push(t_list **stack, t_list **tokens)
{
	if (!stack || !*stack || !tokens || !*tokens)
		return ; 
	ft_lstadd(stack, *tokens);
	*tokens = tokens->next;
}

void		parse(t_list *tokens, t_cmd *cmd)
{
	int		i;
	t_token		*sym;
	t_token		*top;
	t_list		*stack;

	init_stack(stack);
	while (tokens)
	{
		i = -1;
		sym = tokens->content;
		top = stack->content;
		while (g_parsematch[++i].sym)
			if (sym->type == g_parsematch[++i].sym 
				&& top->type == g_parsematch[++i].top)
			{
				if (g_parsematch[i].newtype)
					shift(g_parsematch[i].newtype, &stack, &tokens);
				else
					push(&stack, &tokens);
				break;
			}
		if (g_parsematch[i].sym == ERROR)
			return (-1); // ERROR
//		get_cmd_members();
	}
}
