/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:44:07 by juduval           #+#    #+#             */
/*   Updated: 2023/01/10 17:09:52 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int nb)
{
	unsigned int	check;

	check = 2;
	if (nb == 1)
		return (1);
	else if (nb == 0)
		return (0);
	else if ((nb % 2) != 0)
		return (0);
	while (check < nb)
		check = check * 2;
	if (check == nb)
		return (1);
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	int	i = 6;
	printf("%d\n",is2p(i));
	return (0);
}*/
