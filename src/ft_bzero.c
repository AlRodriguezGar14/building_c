void	ft_bzero(void *buffer, unsigned long len)
{
	unsigned char	*p;

	p = buffer;
	while (len--)
	{
		*p++ = 0;
	}
}
