#include <stdio.h>

int is_prime(unsigned int nb)
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

void    fprime(unsigned int nb)
{
    unsigned int    i;

    i = 2;
    if (nb == 1)
    {
        printf("1\n");
        return ;
    }
    else if (is_prime(nb))
    {
        printf("%d\n", nb);
        return ;
    }
    while (nb >= i)
    {
        if (is_prime(i) && nb % i == 0)
        {
            if (nb > i)
                printf("%d*", i);
            else if (nb == i)
                printf("%d", i);
            nb /= i;
            i = 2;
        }
        else
            i++;
    }
    printf("\n");
}