// Last location of c in str
#include <stdio.h>

char *ft_strrchr(char *str, int c)
{

    int idx = 0;

    while (str[idx] != '\0')
        idx++;
    while (idx > 0 && str[idx] != (char)c)
    {
        idx--;
    }
    if (str[idx] == (char)c)
        return (char*)&str[idx];
    else
        return NULL;
}
