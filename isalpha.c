// ascii values from A to Z and a to z
int ft_isalpha(int c)
{
    if ((c >= 65 && c <= 90) 
        || (c >= 97 && c <= 122))
    {
        return 1;
    }
    return 0;
}
