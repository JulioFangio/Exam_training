/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:26:00 by juduval           #+#    #+#             */
/*   Updated: 2023/01/18 14:53:37 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    putnbr(unsigned int  nb)
{
    char    res;
    
    if (nb <=9)
    {
        res = 48 + nb;
        write(1, &res, 1);
    }
    else
    {
        putnbr(nb / 10);
        putnbr(nb % 10);
    }
}

int is_m3(unsigned int nb)
{
    unsigned int up;
    unsigned int ladder;

    up = 3;
    ladder = 1;
    if (nb < 3)
        return (0);
    while (up * ladder <= nb)
    {
        if (up * ladder == nb)
            return (1);
        ladder++;
    }
    return (0);
}

int is_m5(unsigned int nb)
{
    unsigned int up;
    unsigned int ladder;

    up = 5;
    ladder = 1;
    if (nb < 5)
        return (0);
    while (up * ladder <= nb)
    {
        if (up * ladder == nb)
            return (1);
        ladder++;
    }
    return (0);
}
void    fizzbuzz()
{
    unsigned int i;
    
    i = 1;
    while (i <= 100)
    {
        if (is_m3(i) && is_m5(i))
            write (1, "fizzbuzz\n", 9);
        else if (is_m3(i))
            write (1, "fizz\n", 5);
        else if (is_m5(i))
            write (1, "buzz\n", 5);
        else
        {
            putnbr(i);
            write (1, "\n", 1);
        }
        i++;
    }
}

int main(void)
{
    fizzbuzz();
    return (0);
}