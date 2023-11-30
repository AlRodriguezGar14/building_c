#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	while (idx > 0 && str[idx] != (char)c)
	{
		idx--;
	}
	if (str[idx] == (char)c)
		return ((char *)&str[idx]);
	else
		return (NULL);
}
