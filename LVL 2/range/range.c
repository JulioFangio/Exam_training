/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:32 by juduval           #+#    #+#             */
/*   Updated: 2023/01/16 16:49:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int *tab;
    int i;

    i = 0;
    if (end == start)
        tab = malloc(1 * sizeof(int));
    else if (start < end)
        tab = malloc((end - start + 1) * sizeof(int));
    else if (start > end)
        tab = malloc((start - end + 1) * sizeof(int));
    if (!tab)
        return (NULL);
    if (start <= end)
    {
        while (start <= end)
        {
            tab[i] = start;
            i++;
            start++;
        }
    }
    else if (start > end)
    {
        while (start >= end)
        {
            tab[i] = start;
            i++;
            start--;
        }
    }
    return (tab);
}

int main(void)
{
    int start = 3;
    int end = 3;
    int *tab = ft_range(start, end);
    int i = 0;

    while (i < 1)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}