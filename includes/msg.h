#ifndef MSG_H
#define MSG_H

#include "irc.h"

# define RPL_WELCOME(x, y, z)			"001", 3, x, y, z

# define ERR_NOSUCHNICK(x, y)			"401", 1, x, y
# define ERR_TOOMANYTARGETS(x, y, z)		"407", 4, x, y, z
# define ERR_NORECIPIENT(x, y)			"411", 1, x, y
# define ERR_NOTEXTOSEND(x)			"412", 1, x

# define ERR_NONICKNAMEGIVEN(x)			"431", 1, x
# define ERR_ERRONEUSNICKNAME(x)		"432", 1, x
# define ERR_NICKNAMEINUSE(x)			"433", 1, x
# define ERR_NEEDMOREPARAMS(x)			"461", 1, x
# define ERR_ALREADYREGISTERED(x)		"462", 1, x

# define ERR_LENGPASS(x)			"600", 1, x
# define ERR_REGISTERORDER(x)			"601", 1, x

# define RPL_MSG(x, y)				"650", 2, x, y

void		rpl_welcome(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_nonicknamegiven(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_erroneusnickname(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_nicknameinuse(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_needmoreparams(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_alreadyregistered(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_lengpass(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		err_registerorder(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

void		rpl_msg(t_answer *answer, char *buf_stdin,
		t_prompt *prompt);

#endif 
