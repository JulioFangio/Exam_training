void    ft_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}

// #include <stdio.h>

// int main(void)
// {
//     int a = 10;
//     int b = 15;

//     ft_swap(&a, &b);
//     printf("%d\n", a);
//     printf("%d\n", b);
// }