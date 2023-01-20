/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:10:21 by juduval           #+#    #+#             */
/*   Updated: 2023/01/10 18:06:31 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[0] == '\0')
	{
		write(1, "1\n", 2);
		return ;
	}
	while (s2[i] && s1[j])
	{
		if (s1[j] == s2[i])
			j++;
		i++;
	}
	if (s1[j] == '\0')
	{
		write(1, "1\n", 2);
		return ;
	}
	write(1, "0\n", 2);
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	else
		write(1, "\n", 1);
	return (0);
}
