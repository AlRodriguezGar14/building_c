#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}
