#include "../libft.h"

int	ft_lstsize(t_list *list)
{
	int	idx;

	idx = 0;
	while (list)
	{
		idx++;
		list = list->next;
	}
	return (idx);
}
