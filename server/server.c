
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}


int power(int nb, int power)
{
	int res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	return (res);
}

void    signal_hundler(int  signalId)
{
    static int i;
    static char char_binary[8];
    int         j;
    int         num;


    if (signalId == SIGUSR1)
        char_binary[i] = '1';

    else if (signalId == SIGUSR2)
        char_binary[i] = '0';
    i++;
    if (i == 8)
    {
        j = 0;
        num = 0;
        while (j < 8)
        {
            if (char_binary[j] == '1')
            {
                num += power(2, 7 - j);
            }
            j++;
        }
        ft_putchar(num);
        i = 0;
    }
}
void	translate_message(int num)
{
	static int	power;
	static int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}
int main ()
{

   
    printf("my id : %d\n",getpid());
    signal(SIGUSR1, signal_hundler);
	signal(SIGUSR2, signal_hundler);
		while (42)
			pause();

    return (0);
}