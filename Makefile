# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 00:35:24 by ariard            #+#    #+#              #
#    Updated: 2017/06/23 17:08:43 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ircd client

CC		=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g
D_FLAGS		=	

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=	-ltermcap
SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SERV_OBJ	=	$(OBJ_DIR)serv/server.o
CLI_OBJ		=	$(OBJ_DIR)cli/client.o

SRC_BASE	=	\
answer/rpl_welcome.c\
cli/add_buf.c\
cli/answer_destroy.c\
cli/answer_execute.c\
cli/answer_init.c\
cli/client.c\
cli/loop.c\
cli/parse_bufsocket.c\
cli/read_socket.c\
cli/read_stdin.c\
cli/send_buf.c\
cli/terminal.c\
cmds/cmd_nick.c\
cmds/cmd_pass.c\
cmds/cmds_user.c\
cmds/execute_cmds.c\
database/client_cmp.c\
database/client_destroy.c\
database/client_init.c\
database/client_print.c\
database/cmd_destroy.c\
database/user_cmp.c\
database/user_init.c\
debug/print_bucket.c\
debug/print_cmd.c\
debug/print_cmds.c\
debug/print_tokens.c\
parse/get_cmd_members.c\
parse/lexer.c\
parse/parse.c\
parse/token_destroy.c\
prompt/prompt_add.c\
prompt/prompt_clear.c\
prompt/prompt_init.c\
prompt/prompt_new.c\
prompt/prompt_push.c\
prompt/term_add.c\
prompt/term_del.c\
prompt/term_init.c\
prompt/term_insert.c\
prompt/term_newline.c\
prompt/term_put.c\
prompt/term_up.c\
serv/accept_cli.c\
serv/cirbuf_read.c\
serv/construct_msg.c\
serv/daemon.c\
serv/first_parse.c\
serv/init_server.c\
serv/loop.c\
serv/manage_cmds.c\
serv/read_sockets.c\
serv/server.c\
serv/sockets.c\
serv/write_sockets.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
OBJS		:=	$(filter-out $(SERV_OBJ), $(OBJS))
OBJS		:=	$(filter-out $(CLI_OBJ), $(OBJS))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

ircd : $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(SERV_OBJ)
	@ $(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(SERV_OBJ) $(FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $@ \033[0m\033[K\n"

client : $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(CLI_OBJ)
	@ $(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(CLI_OBJ) $(FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $@ \033[0m\033[K\n"


$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
