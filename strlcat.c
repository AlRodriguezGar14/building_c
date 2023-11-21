#include <stdio.h>

size_t ft_strlcat(char *dest, char *src, size_t dest_size)
{
    size_t idx = 0;
    size_t copy_size = 0;
    size_t real_dest_size;

    while (dest[copy_size] != '\0' && copy_size < dest_size - 1)
        copy_size++;


    while (copy_size < dest_size - 1 && src[idx] != '\0')
    {
        dest[copy_size] = src[idx];
        copy_size++;
        idx++;
    }

    dest[copy_size] = '\0';

    while (src[idx] != '\0')
    {
        idx++;
        copy_size++;
    }

    return copy_size;
}
