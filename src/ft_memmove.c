// memmove it can copy forwars and backwards, while memcpy only works forward
// memmove is safer than memcpy because deals with overlapping buffers

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

static void	cpy_from_start_to_end(char *dest, const char *src, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

static void	cpy_from_end_to_start(char *dest, const char *src, size_t n)
{
	size_t	idx;

	idx = n;
	while (idx > 0)
	{
		dest[idx - 1] = src[idx - 1];
		idx--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;

	char_dest = (char *)dest;
	char_src = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (char_dest < char_src)
		cpy_from_start_to_end(char_dest, char_src, n);
	else
		cpy_from_end_to_start(char_dest, char_src, n);
	return (dest);
}
