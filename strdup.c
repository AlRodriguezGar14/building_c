#include <stdlib.h>
#include <stdio.h>
#include "libft.h"


char *ft_strdup(const char *str1)
{
    int len = ft_strlen(str1) + 1;

    char *out = (char *)malloc(len * sizeof(char));
    if (out == NULL)
        return NULL;
 
    ft_memcpy(out, (char *)str1, len);
    return out;
}
