#ifndef PROMPT_H
#define PROMPT_H

#include "irc.h"

struct s_cursor
{
	short	x;
	short	y;
};

struct s_prompt
{
	int		col;
	int		row;
	int		len;
	char		*prompt;
	t_cursor	cursor;
};

void		prompt_init(t_prompt *prompt);					

void		prompt_clear(t_prompt *prompt);	

void		prompt_add(t_prompt *prompt, char *buf);

void		prompt_new(t_prompt *prompt);

void		prompt_push(t_prompt *prompt, char *bufstdin, char *buf);

void		term_insert(char *str);

void		term_right(int size);

void		term_del(int size);

int		term_put(int c);

void		term_newline(int size);

int		term_init(void);

void		term_up(int size);

/* Termcaps functions */

extern char	*tgoto(const char *cstring, int hpos, int vpos);

extern int	tputs(const char *str, int affcnt, int (*putc)(int));

extern int	tgetent(char *bp, const char *name);

extern char	*tgetstr(char *name, char **area);

extern int	tgetnum(char *name);

#endif
