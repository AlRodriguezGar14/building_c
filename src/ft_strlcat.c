#include <stdio.h>
#include "../libft.h"

//why use ret = ft_strlcpy()
// src is already at the possition where attaching anything else
// just concats and doesn't replace
// imagine:
// dst_len = 5, sizeof_dst = dstsize = 20.
// maximum elements from src to copy is: 20 - 5 = 15
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	ret;

	idx = -1;
	while (++idx < dstsize && *dst)
		dst++;
	ret = ft_strlcpy(dst, src, dstsize - idx);
	return (ret + idx);
}
