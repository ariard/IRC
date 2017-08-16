#ifndef TYPES_H
#define TYPES_H

#include "irc.h"

typedef struct s_channel	t_channel;
typedef struct s_server		t_server;
typedef struct s_streamcmd	t_streamcmd;
typedef struct s_client		t_client;
typedef struct s_user		t_user;
typedef struct s_lexmatch	t_lexmatch;
typedef struct s_parsematch	t_parsematch;
typedef struct s_token		t_token;
typedef struct s_cmd		t_cmd;
typedef struct s_cmdmatch	t_cmdmatch;

typedef struct s_cursor		t_cursor;
typedef struct s_prompt		t_prompt;
typedef struct s_keymatch	t_keymatch;
typedef struct s_answer		t_answer;
typedef	struct s_ansmatch	t_ansmatch;
//typedef	enum e_ttystate		t_ttystate;

#endif
