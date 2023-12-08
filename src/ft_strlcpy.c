// Guarantees the null termination when there's space
// Avoids buffer overflows

#include <stdio.h>
#include "../libft.h"

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	len;
// 	size_t	idx;
// 	int		sizeof_null;
//
// 	len = ft_strlen(src);
// 	if (size <= 0)
// 		return (len);
// 	idx = 0;
// 	sizeof_null = 1;
// 	while ((idx++ < size - sizeof_null) && (*dest++ = *src++) != '\0')
// 		*dest = '\0';
// 	return (len);
// }

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	len;

	len = ft_strlen(src);
	if (size <= 0)
		return (len);
	idx = 0;
	while (idx < size - 1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (len);
}

// int main(void)
// {
//	   char    dest[10] = {0};
//	   char    src[] = "Hello";
//	   ft_strlcpy(dest, src, 3);
//	   printf("dest: %s\n", dest);
//	   return (0);
// }
