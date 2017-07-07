#ifndef MSG_H
#define MSG_H

#include "irc.h"

# define RPL_WELCOME(x, y, z)		"001", 3, x, y, z	

# define ERR_NONICKNAMEGIVEN		"431", 0
# define ERR_ERRONEUSNICKNAME		"432", 0
# define ERR_NICKNAMEINUSE		"433", 0
# define ERR_NEEDMOREPARAMS		"461", 0
# define ERR_ALREADYREGISTERED		"462", 0

# define ERR_LENGPASS			"600", 0
# define ERR_REGISTERORDER		"601", 0

#endif 
