#include <stdio.h>

void *ft_memcpy(void *dest, void *src, size_t bytes_copied)
{
    int     idx = -1;
    char    *char_dest = (char *)dest;
    char    *char_src = (char *)src;

    while (idx++ != bytes_copied)
    {
        char_dest[idx] = char_src[idx];
    }

    return dest;
}
