#include <unistd.h>

static void    put_nbr(unsigned int nb)
{
    char    res;

    if (nb <= 9)
    {
        res = nb + 48;
        write(1, &res, 1);
    }
    else
    {
        put_nbr(nb / 10);
        put_nbr(nb % 10);
    }
}

int atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}

void    tab_mult(unsigned int nb)
{
    int i;

    i = 1;
    while (i <= 9)
    {
        put_nbr(i);
        write (1, " x ", 3);
        put_nbr(nb);
        write (1, " = ", 3);
        put_nbr(i * nb);
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        tab_mult(atoi(av[1]));
    else
        write(1, "\n", 1);
    return (0);
}