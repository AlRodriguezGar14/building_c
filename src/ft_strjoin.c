#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*output;

	if (!s1)
		return (NULL);
	total_len = ft_strlen(s1) + 1 + ft_strlen(s2) + 1;
	output = (char *)ft_calloc(total_len - 1, sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strlcat(output, (char *)s1, total_len);
	ft_strlcat(output, (char *)s2, total_len);
	return (output);
}
// char *ft_strjoin(char const *s1, char const *s2)
// {
//	   size_t s1_len = ft_strlen(s1);
//	   size_t total_len = s1_len + ft_strlen(s2);
//	   size_t idx = 0;
//	   char *output = (char *)malloc((total_len) * sizeof(char));
//	   if (output == NULL) return NULL;
//
//	   while (idx < s1_len)
//	   {
//		   output[idx] = *s1;
//		   idx++;
//		   s1++;
//	   }
//	   while (idx < total_len)
//	   {
//		   output[idx] = *s2;
//		   idx++;
//		   s2++;
//	   }
//	   output[idx] = '\0';
//
//	   return output;
// }
