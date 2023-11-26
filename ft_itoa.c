#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


int get_length(int n)
{
    int len;

    len = 1;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

int get_operator(long n)
{
    int operator;

    operator = 1;
    while (n > 9)
    {
        n /= 10;
        operator *= 10;
    }
    return operator;
}

void    build_output(int len, int simbol, long out_n, int operator, char *out)
{
    int idx;

    idx = 0;
    if (simbol < 0)
    {
        out[idx] = '-';
        idx++;
    }
    while (idx < len - 1)
    {
        out[idx] = (out_n / operator) + '0';
        out_n %= operator;
        operator /= 10;
        idx++;
    }
    out[idx] = '\0';

}
char *ft_itoa(int n)
{
    int operator, len;
    long simbol, out_n;
    char *out;
    
    simbol = (n < 0) ? -1 : 1;

    out_n = n * simbol;

    operator = get_operator(out_n);
    len = get_length(operator);
    if (simbol < 0)
        len++;

    out = (char *)malloc((len) * sizeof(char));
    if (!out)
        return NULL;

    build_output(len, simbol, out_n, operator, out);
    return out;
}
