#include <stdio.h>
#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	idx;

	if (!s)
		return ;
	idx = 0;
	while (*s)
	{
		f(idx, s);
		idx++;
		s++;
	}
}
