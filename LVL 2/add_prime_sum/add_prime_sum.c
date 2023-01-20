/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:09:04 by juduval           #+#    #+#             */
/*   Updated: 2023/01/19 14:46:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_isprime(unsigned int c)
{
	unsigned int	i;

	i = 2;
	if (c < 2 || (c % 2 == 0 && c != 2))
		return (0);
	while (i <= (c / i))
	{
		if ((c % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	add_prime_sum(unsigned int c)
{
	unsigned int	i;
	unsigned int	ladder;

	ladder = 0;
	i = 2;
	if (c < 2)
	{
		write(1, "0\n", 2);
		exit (0);
	}
	while (i <= c)
	{
		if(ft_isprime(i))
			ladder += i;
		i++;
	}
	return (ladder);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	result;
	
	i = 0;
	result = 0;
	while(str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

void	putnbr(unsigned int c)
{
	char	res;

	if (c <= 9)
	{
		res = c + '0';
		write(1, &res, 1);
	}
	else
	{
		putnbr(c / 10);
		putnbr(c % 10);
	}
}

int	main(int ac, char **av)
{
	unsigned int	result;

	if (ac == 2)
	{
		result = add_prime_sum(ft_atoi(av[1]));
		putnbr(result);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}

// int main(void)
// {
// 	char	str[] = "7";
// 	unsigned int	result;

// 	result = add_prime_sum(ft_atoi(str));
// 	putnbr(result);
// 	return (0);
// }