#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

static int	check_match(const char haystack, const char *needle)
{
	size_t	idx;

	idx = 0;
	while (needle[idx])
	{
		if (haystack == needle[idx])
			return (0);
		idx++;
	}
	return (ft_isprint(haystack));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*output;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && check_match(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		output = (char *)ft_calloc(1, sizeof(char));
		if (!output)
			return (NULL);
		return (output);
	}
	end = ft_strlen(s1);
	while (end > start && check_match(s1[end], set) == 0)
		end--;
	output = (char *)ft_calloc((end - start) + 2, sizeof(char));
	if (output == NULL)
		return (NULL);
	s1 += start;
	ft_strlcpy(output, s1, (end - start) + 2);
	return (output);
}
//
// int main() {
//	   char *s1 = "\n\t  hola ";
//	   char *s2 = "";
//
//	   char *out = ft_strtrim(s1, s2);
//	   printf("out: %s\n", out);
// }
