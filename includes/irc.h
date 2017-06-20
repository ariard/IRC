#ifndef IRC_H
#define IRC_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>


/* Seerver side */

int	daemonize(void);

#endif
