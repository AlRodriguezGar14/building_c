#include "../libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (TRUE);
	return (FALSE);
}
