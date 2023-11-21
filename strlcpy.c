// Guarantees the null termination when there's space
// Avoids buffer overflows

#include <stdio.h>

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    int idx = 0;

    size_t src_len = 0;
    while (src[src_len] != 0)
        src_len++;

    while (idx < size - 1 && src[idx] != '\0')
    {
        dest[idx] = src[idx];
        idx++;
    }


    dest[idx] = '\0';

    return src_len;
}
