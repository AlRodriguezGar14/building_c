#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct number_info
{
	char	*out;
	int		len;
	int		simbol;
	int		operator;
	long	out_n;
}	t_number_info;

static int	get_length(int n)
{
	int	len;

	len = 1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	get_operator(long n)
{
	int	operator;

	operator = 1;
	while (n > 9)
	{
		n /= 10;
		operator *= 10;
	}
	return (operator);
}

void	build_output(t_number_info *output)
{
	int	idx;

	idx = 0;
	if (output->simbol < 0)
	{
		output->out[idx] = '-';
		idx++;
	}
	while (idx < output->len - 1)
	{
		output->out[idx] = (output->out_n / output->operator) + '0';
		output->out_n %= output->operator;
		output->operator /= 10;
		idx++;
	}
	output->out[idx] = '\0';
}

char	*ft_itoa(int n)
{
	t_number_info	output;

	if (n < 0)
		output.simbol = -1;
	else
		output.simbol = 1;
	output.out_n = n;
	output.out_n *= output.simbol;
	output.operator = get_operator(output.out_n);
	output.len = get_length(output.operator);
	if (output.simbol < 0)
		output.len++;
	output.out = (char *)malloc((output.len) * sizeof(char));
	if (!output.out)
		return (NULL);
	build_output(&output);
	return (output.out);
}
