// It's better to use memset


void ft_bzero(void *buffer, unsigned long len)
{
    unsigned char   *p = buffer;

    while (len--)
    {
        *p++ = 0;
    }
}
