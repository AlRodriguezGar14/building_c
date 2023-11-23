#include <stddef.h>
#include <stdio.h>
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
    size_t idx = 0;
    int match_idx;

    if (*needle == '\0')
        return (char *)haystack;

    while (idx < loc && haystack[idx])
    {
        match_idx = idx;
        if (haystack[idx] == *needle)
        {
            while (haystack[idx] == *needle && idx < loc)
            {
                needle++;
                if (!*needle || idx >= loc)
                    return (char *)&haystack[match_idx];
                idx++;
            }
            needle -= (idx - match_idx); // reset needle in the case it is not a match
        }
        idx++;
    }
    return NULL;
}
