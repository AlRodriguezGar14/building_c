#include <stdio.h>

int ft_atoi(const char *str)
{
    int operator = 1;
    long output = 0;

    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;

    if (*str == '-')
    {
        operator *= -1;
        str++;
    }
    else if (*str == '+') 
        str++;

    while (*str >= '0' && *str <= '9')
    {
        output = output * 10 + (*str - '0');
        str++;
    }
    
    return output * operator;
}
