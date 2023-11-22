#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(int n_elements, int data_type)
{
    int idx = 0;
    char *assignable;
    int total = n_elements * data_type;

    if (total == 0)
        return NULL;

    void *allocated = malloc(total);
    if (allocated == NULL)
        return NULL;

    assignable = (char *)allocated;
    while (idx < total)
    {
    assignable[idx] = 0;
        idx++;
    }

    return allocated;
}
