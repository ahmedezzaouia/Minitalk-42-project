/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:20:30 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/04/02 17:50:46 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb < 0 && sign > 0)
		return (-1);
	if (nb < 0 && sign < 0)
		return (0);
	return (nb * sign);
}

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
		usleep(200);
		i--;
	}
}

int	main(int ac, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		exit (EXIT_FAILURE);
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			write(1, "Error.\nInvalid PID.\n", 30);
			exit (EXIT_FAILURE);
		}
		while (argv[2][i])
			send_char_bits(argv[2][i++], pid);
	}
	exit (EXIT_SUCCESS);
}
