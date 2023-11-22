#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    int idx = 0;
    const unsigned char *a = s1;
    const unsigned char *b = s2;

    while (idx < n - 1 && (*a != '\0' || *b != '\0'))
    {
        if (*a != *b)
            break;
        idx++;
        a++;
        b++;
    }
    return (int)*a - (int)*b;
}
