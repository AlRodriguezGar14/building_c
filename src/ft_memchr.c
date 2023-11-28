// First instance of uint char c in n bytes of the memory block starting at str
// n is very important because if not memchr doesn't know when to stop
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*content;

	idx = 0;
	content = str;
	while (idx < n)
	{
		if (*content == (unsigned char)c)
			return ((void *)content);
		idx++;
		content++;
	}
	return (NULL);
}
