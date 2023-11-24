#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t idx = 0;
    char *substr;
    
    if (len == 0 || start >= ft_strlen(s))
    {
        substr = (char *)malloc(sizeof(char));
        *substr = '\0';
        return substr;
    }

    substr = (char *)malloc(len + 1 * sizeof(char));
    if (substr == NULL) return NULL;

    while (idx < len)
    {
        substr[idx] = s[start];
        idx++;
        start++;
    }
    substr[idx] = '\0';

    return substr;
}
