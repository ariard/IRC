#include "irc.h"

void		add_buf(char buf[], t_prompt *prompt, int key, int sock)
{
	(void)sock;
	if (key > 255 || ft_strlen(buf) >= CLIBUF)
		return ; 
	ft_strncat(buf, (char *)&key, 1);
	write(1, &key, 1);
	prompt_add(prompt);
}
