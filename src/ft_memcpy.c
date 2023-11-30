#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t bytes_copied)
{
	size_t	idx;
	char	*char_dest;
	char	*char_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	idx = 0;
	char_dest = (char *)dest;
	char_src = (char *)src;
	while (idx < bytes_copied)
	{
		char_dest[idx] = char_src[idx];
		idx++;
	}
	return (dest);
}
