/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:06:57 by juduval           #+#    #+#             */
/*   Updated: 2023/01/18 19:16:55 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char    temp;
    int     end;

    temp = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    begin.y = 0;

    end = 0;
    while (begin.y < size.y)
    {
        end = 0;
        begin.x = 0;
        while (tab[begin.y][begin.x] && end == 0)
        {
            if (tab[begin.y][begin.x] == 'F')
            {
                if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == temp)
                {
                    tab[begin.y][begin.x - 1] = 'F';
                    end = 1;
                }
                if (tab[begin.y][begin.x + 1] != '\0' && tab[begin.y][begin.x + 1] == temp)
                {
                    tab[begin.y][begin.x + 1] = 'F';
                    end = 1;
                }
                if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == temp)
                {
                    tab[begin.y - 1][begin.x] = 'F';
                    end = 1;
                }
                if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == temp)
                {
                    tab[begin.y + 1][begin.x] = 'F';
                    end = 1;
                }
            }
            begin.x++;
        }
        if (end == 0)
            begin.y++;
        else
            begin.y = 0;
    }
}

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
