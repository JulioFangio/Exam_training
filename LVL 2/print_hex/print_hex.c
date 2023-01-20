/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:25 by juduval           #+#    #+#             */
/*   Updated: 2023/01/18 16:03:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int atoi(char *str)
{
    int i;
    int res;

    i = 0;
    while (str[i])
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res);
}

void    p_hex(unsigned int nb)
{
    char    *base;
    char    res;

    base = "0123456789abcdef";
    if (nb <= 15)
    {
        res = base[nb];
        write(1, &res, 1);
    }
    else
    {
        p_hex(nb / 16);
        p_hex(nb % 16);
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        p_hex(atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}