#include <stdlib.h>
#include <stdio.h>
#include "libft.h"


char *ft_strdup(const char *str1)
{
    int len = ft_strlen(str1);
    int idx = 0;

    char *out = (char *)malloc((len + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    while (idx < len)
    {
        out[idx] = str1[idx];
        idx++;
    }
    out[idx] = '\0';
    
    return out;
}
