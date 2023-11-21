// memmove it can copy forwars and backwards, while memcpy only works forward
// memmove is safer than memcpy because deals with overlapping buffers

#include <stdio.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char    *char_dest = (char *)dest;
    char    *char_src = (char *)src;
    char    *tmp = (char *)malloc(sizeof(char) * n);
    
    if (char_dest == char_src)
        return char_dest;

    if (tmp == NULL)
    {
        return NULL;
    }

    int     idx = 0;
    while(idx < n)
    {
        tmp[idx] = char_src[idx];
        idx++;
    }

    idx = 0;
    while(idx < n)
    {
        char_dest[idx] = tmp[idx];
        idx++;
    }

    free(tmp);

    return dest;
}
