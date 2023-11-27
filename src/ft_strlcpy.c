// Guarantees the null termination when there's space
// Avoids buffer overflows

#include <stdio.h>
#include "../libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t idx = 0;
    size_t len = ft_strlen(src);

    if (size <= 0)
        return len;

    while (idx < size - 1 && src[idx] != '\0')
    {
        dest[idx] = src[idx];
        idx++;
    }
    dest[idx] = '\0';

    return len;
}
