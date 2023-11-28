unsigned long	ft_strlen(const char *str)
{
	unsigned long	idx;

	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}
