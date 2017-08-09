#include "irc.h"

static t_parsematch	g_parsematch[] =
{
	{COLON, TERM, 0},
	{NOSPCRLFCL, COLON, PREFIX},
	{NOSPCRLFCL, PREFIX, PREFIX},
	{SPACE_PREFIX, PREFIX, 0},
	{NOSPCRLFCL, SPACE_PREFIX, CMD},
	{NOSPCRLFCL, CMD, CMD},
	{SPACE, CMD, 0},
	{NOSPCRLFCL, SPACE, 0},
	{NOSPCRLFCL, NOSPCRLFCL, PARAM},
	{NOSPCRLFCL, PARAM, PARAM},
	{SPACE, PARAM, 0},
	{ERROR, 0, 0},
};

static void		init_stack(t_list **stack)
{
	t_token	token;

	token.type = TERM;
	token.value = 0;
	ft_lstadd(stack, ft_lstnew(&token, sizeof(token)));
}

static void		shift(int newtype, void *content, t_token *sym, t_list **tokens)
{
	t_token		*top;
	char	*tmp;
	t_list		*elem;

//	DG("shift");
	if (!tokens || !*tokens  )
		return ; 
	top = content;
	top->type = newtype;
	tmp = top->value;
	top->value = ft_strjoin(top->value, sym->value);
	ft_strdel(&tmp);
	if ((elem = ft_lst_pop(tokens)))
	{
		token_destroy(elem->content, 0);
		free(elem);
		elem = NULL;
	}
}

static void		push_token(t_list **stack, t_list **tokens)
{
//	DG("push");
	if (!stack || !*stack || !tokens || !*tokens)
		return ; 
	ft_lstadd(stack, ft_lst_pop(tokens));
}

static void		morph_tokens(t_token *sym, t_token *top)
{
	if (top->type == PREFIX && sym->type == SPACE)
		sym->type = SPACE_PREFIX;
}

int			parse(t_list **tokens, t_cmd *cmd)
{
	int		i;
	t_token		*sym;
	t_token		*top;
	t_list		*stack;

	stack = NULL;
	init_stack(&stack);
	while (tokens && *tokens)
	{
		i = -1;
		sym = (*tokens)->content;
		top = stack->content;
//		print_tokens(sym, NULL);
//		DG("vs");
//		print_tokens(top, NULL);
		morph_tokens(sym, top);
		while (g_parsematch[++i].sym != ERROR)
			if (sym->type == g_parsematch[i].sym 
				&& top->type == g_parsematch[i].top)
			{
				if (g_parsematch[i].newtype)
					shift(g_parsematch[i].newtype, stack->content, sym, tokens);
				else
					push_token(&stack, tokens);
				break;
			}
		if (g_parsematch[i].sym == ERROR)
			return (-1); // ERROR
	}
	get_cmd_members(&stack, cmd);
	return (0);
}
