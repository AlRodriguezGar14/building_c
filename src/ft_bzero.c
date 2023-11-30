#include <stdio.h>

void	ft_bzero(void *buffer, size_t len)
{
	unsigned char	*p;

	p = buffer;
	while (len--)
	{
		*p++ = 0;
	}
}
