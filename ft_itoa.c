#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_itoa(int n)
{
    int operator = 1;
    int len = 1;
    long simbol = 1;
    long tmp_n;
    long out_n;
    int idx;
    char *out;
    
    if (n < 0)
        simbol *= -1;
    out_n = n * simbol;
    tmp_n = n * simbol;

    // printf("out_n := %d\n", out_n);

    while (tmp_n > 9)
    {
        tmp_n /= 10;
        operator *= 10;
        len++;
    }
    
    if (simbol < 0)
        len++;

    out = (char *)malloc((len+ 1) * sizeof(char));
    if (!out)
        return NULL;

    idx = 0;
    if (simbol < 0)
    {
        *out = '-';
        out++;
        idx++;
    }
    while (idx < len)
    {
        *out = (out_n / operator) + '0';
        out_n %= operator;
        operator /= 10;
        out++;
        idx++;
    }
    *out = '\0';
    out -= idx;   

    return out;
}
//
// int main()
// {
//     char *test  = ft_itoa(-2147483648);
//     printf("tests: %s\n", test);
//     return (0);
// }
