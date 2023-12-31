#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

static size_t	break_content(char const *s, char c, char **out)
{
	char	*tmp;
	size_t	idx;

	tmp = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (tmp == NULL)
		return (-1);
	idx = 0;
	while (s[idx])
	{
		if (s[idx] != c)
		{
			tmp[idx] = s[idx];
			idx++;
		}
		else
			break ;
	}
	*out = ft_strdup(tmp);
	if (*out == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (idx);
}

static size_t	count_words(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (counter);
}

static void	free_output(char **output, size_t counter)
{
	while (counter > 0)
		free(output[--counter]);
	free(output);
}

// count = number of subarrays in out
// Default fail return: -1
char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	idx;
	size_t	count;

	out = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (out == NULL)
		return (NULL);
	count = -1;
	while (*s)
	{
		if (*s != c)
		{
			idx = break_content(s, c, &out[++count]);
			if ((long long)idx == -1)
			{
				free_output(out, count);
				return (NULL);
			}
			s += idx;
		}
		else
			s++;
	}
	return (out);
}

// int main() {
//    char **result;
//    int i;
//
//    // Test 1
//    result = ft_split("		split		this for   me  !	   ",  ' ');
//    printf("Test 1:\n");
//    for (i = 0; result[i] != NULL; i++) {
// 	   printf("%s\n", result[i]);
// 	   free(result[i]);
//    }
//    free(result);
//
//    result = ft_split(",,,,", ',');
//    printf("\nTest 3:\n");
//    for (i = 0; result[i] != NULL; i++) {
// 	   printf("%s\n", result[i]);
// 	   free(result[i]);
//    }
//    free(result);
//
//    return 0;
// }
