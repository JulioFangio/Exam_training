#include <unistd.h>
#include <stdio.h>

int is_prime(unsigned int nb)
{
    unsigned int p;

    p = 2;
    while (p <= (nb / p))
    {
        if (nb % 2 == 0)
            return (0);
        p++;
    }
    return (1);
}

unsigned int fatoi(char  *str)
{
    unsigned int i;
    unsigned int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}

int is_factor()

int main(void)
{
    unsigned int i = 6;

    printf("%d\n", is_prime(i));
    return (0);
}

#include <stdlib.h>
#include <stdio.h>

// void	fprime(unsigned int nb)
// {
// 	unsigned	i;

// 	if (nb == 1)
// 		printf("1");
// 	else
// 	{
// 		i = 1;
// 		while (nb > 1)
// 		{
// 			if (nb % ++ i == 0)
// 			{
// 				printf("%d", i);
// 				nb /= i;
// 				if (nb > 1)
// 					printf("*");
// 				--i;
// 			}
// 		}
// 	}
// }

int	main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}