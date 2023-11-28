#include <stdio.h>
#include "../libft.h"

//why use ret = ft_strlcpy()
// src is already at the possition where attaching anything else
// just concats and doesn't replace
// imagine:
// dest_len = 5, sizeof_dest = dstsize = 20.
// maximum elements from src to copy is: 20 - 5 = 15
size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	idx;
	size_t	ret;

	idx = 0;
	while (idx < dstsize && *dest)
	{
		dest++;
		idx++;
	}
	ret = ft_strlcpy(dest, src, dstsize - idx);
	return (ret + idx);
}
