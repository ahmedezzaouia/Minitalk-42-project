
#include <unistd.h>
#include <stdio.h>
#include <signal.h>






void	send_char_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int main (int ac, char **argv)
{
    int i = 0;
	char *str = argv[1];
    while (argv[1][i])
  	  send_char_bits(argv[1][i++], 13776);
  
  
        
    return (0);
}