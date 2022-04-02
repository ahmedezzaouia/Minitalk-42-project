/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:35:21 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/04/02 15:48:19 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	power(int nb, int power)
{
	int	res;

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

void	convert_binary(char *char_binary)
{
	int	j;
	int	num;

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
}

void	signal_hundler(int signalId)
{
	static int		i;
	static char		char_binary[8];

	if (signalId == SIGUSR1)
		char_binary[i] = '1';
	else if (signalId == SIGUSR2)
		char_binary[i] = '0';
	i++;
	if (i == 8)
	{
		convert_binary(char_binary);
		i = 0;
	}
}

int	main(void)
{
	printf("my id : %d\n", getpid());
	signal(SIGUSR1, signal_hundler);
	signal(SIGUSR2, signal_hundler);
	while (1)
		pause();
	return (0);
}
