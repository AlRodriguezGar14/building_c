#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

// TODO: I'm using ft_calloc to guarantee it is null terminated. Double check if malloc is not mandatory

size_t break_content(char const *s, char c, char **out)
{
    char *tmp;
    size_t idx;

    tmp = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
    if (tmp == NULL)
        return 0;

    idx = 0;
    while (s[idx])
    {
        if (s[idx] != c)
        {
            tmp[idx] = s[idx];
            idx++;
        } else {
            break;
        }
    }
    *out = ft_strdup(tmp);
    free(tmp);

    return idx;
}

size_t count_words(char const *s, char c)
{
    size_t counter = 0;

    while (*s)
    {
        if (*s != c)
        {
            counter++;
            while (*s && *s != c)
                s++;
        }
        else 
            s++;
    }
    return counter;
}

char **ft_split(char const *s, char c)
{
    char **out = NULL;
    size_t idx = 0;
    size_t count = 0; // number of subarrays in out
    
    size_t counter = count_words(s, c);
    out = ft_calloc(counter + 1, sizeof(char *));
    while (*s)
    {
        if (*s != c)
        {
            idx = break_content(s, c, &out[count]);
            if (idx <= 0)
                idx = 1;
            s += idx;
            count++;
        }
        else
            s++;
    }
    return out;
}

// int main() {
//     char **result;
//     int i;
//
//     // Test 1
//     result = ft_split("      split       this for   me  !       ",  ' ');
//     printf("Test 1:\n");
//     for (i = 0; result[i] != NULL; i++) {
//         printf("%s\n", result[i]);
//         free(result[i]);
//     }
//     free(result);
//
//     result = ft_split(",,,,", ',');
//     printf("\nTest 3:\n");
//     for (i = 0; result[i] != NULL; i++) {
//         printf("%s\n", result[i]);
//         free(result[i]);
//     }
//     free(result);
//
//     return 0;
// }
