#include <unistd.h>

void    capitalizer(char *str)
{
    int i;
    int tmp;

    i = 0;
    while (str[i] < 33)
    {
        write(1, &str[i], 1);
        i++;
    }
    tmp = i;
    while (str[i])
    {
        if (str[i + 1] == 32 && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        else if (str[i + 1] >= 33 && (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] += 32;
        else if (str[i + 1] == '\0' && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        else if (str[i + 1] >= '\0' && (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] = str[i];
        i++;
    }
    while (str[tmp])
    {
        write(1, &str[tmp], 1);
        tmp++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac >= 2)
    {
        while (i < ac)
        {
            capitalizer(av[i]);
            i++;
        }
    }
    else 
        write(1, "\n", 1);
    return (0);
}