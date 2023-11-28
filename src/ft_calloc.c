#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

void	*ft_calloc(int n_elements, int data_type)
{
	char	*assignable;
	int		total;
	void	*allocated;

	total = n_elements * data_type;
	allocated = malloc(total);
	if (allocated == NULL)
		return (NULL);
	assignable = (char *)allocated;
	ft_memset(assignable, 0, total);
	return (allocated);
}
