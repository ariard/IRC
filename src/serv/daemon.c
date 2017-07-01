#include "irc.h"

static int	daemonize_setup(int pid)
{
	int	status;
	int	fd;

	if ((status = fork()) < 0)
		return (1);
	if (status > 0)
		exit(0);
	if (setsid() < 0)	
		return (1);
	if ((fd = open("/dev/null", O_RDWR)) < 0)
		return (1);
	if (dup2(fd, 0) < 0)
		return (1);
	if (dup2(fd, 1) < 0)
		return (1);
	if (dup2(fd, 2) < 0)
		return (1);
	umask(0);
	if (chdir("/") < 0)
		return (1);
	kill(pid, SIGKILL);
	return (0);
}

int		daemonize(void)
{
	int	pid;
	int	status;

	if ((pid = getpid()) < 0)
		return (1);
	if ((status = fork()) < 0)
		return (1);
	if (status > 0)
		while (1);
	if (status == 0)
		return (daemonize_setup(pid));
	return (1);
}
