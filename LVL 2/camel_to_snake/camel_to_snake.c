#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

char    *ca_to_sna(char *str)
{
    int i;
    int j;
    int len;
    char    *res;

    i = 0;
    j = 0;
    len = 1;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            len = len + 2;
            i++;
        }
        else
        {
            len++;
            i++;
        }
    }
    res = malloc (len * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            res[j] = str[i];
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            res[j] = '_';
            j++;
            res[j] = str[i] + 32;
        }
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}


int main(int ac, char **av)
{
    if (ac == 2)
        putstr(ca_to_sna(av[1]));
    else
        write(1, "\n", 1);
    return (0);
}