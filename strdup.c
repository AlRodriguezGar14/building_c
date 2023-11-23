#include <stdlib.h>
#include <stdio.h>

// TOOO: Replace this with the import from the library lift.h once built
static unsigned long ft_strlen2(const char *str)
{
    unsigned long idx;
    
    idx = 0;

    while (str[idx] != 0)
        idx++;
    return idx;
}

char *ft_strdup(const char *str1)
{
    int len = ft_strlen2(str1);
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
