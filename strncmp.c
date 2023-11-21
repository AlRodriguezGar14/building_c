// compare lexicographically 

#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int idx = 0;
    while (idx < n - 1 && *s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
    {
        idx++;
        s1++;
        s2++;
    }
    return (int)*s1 - (int)*s2;
}
