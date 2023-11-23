#include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char *dest, char *src, size_t dstsize)
{
    size_t idx = 0;
    size_t ret;

    while (idx < dstsize && *dest)
    {
        dest++;
        idx++;
    }
    // src is already at the possition where attaching anything else just concats and doesn't replace
    // imagine:
    // dest_len = 5, sizeof_dest = dstsize = 20.
    // maximum elements from src to copy is: 20 - 5 = 15
    ret = ft_strlcpy(dest, src, dstsize - idx); 

    // chars "copied" (appended) + dest_len
    return ret + idx;
}

