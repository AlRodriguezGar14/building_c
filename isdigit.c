int ft_isdigit(int c)
{
    if (c >= 48 && c <= 57) // ascii: 48 = 0, 57 = 9
    {
        return 1;
    }
    return 0;
}
