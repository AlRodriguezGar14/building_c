#include <stddef.h>
#include <stdio.h>
#include "../libft.h"

// loc is the maximum number of characters to compare in the haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	idx;
	size_t	needle_idx;

	if (*needle == '\0')
		return ((char *)haystack);
	idx = 0;
	while (idx < loc && haystack[idx])
	{
		needle_idx = 0;
		while (haystack[idx + needle_idx] == needle[needle_idx]
			&& (idx + needle_idx) < loc)
		{
			needle_idx++;
			if (!needle[needle_idx])
				return ((char *)&haystack[idx]);
		}
		idx++;
	}
	return (NULL);
}
