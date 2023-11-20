/*
 * This function determines if a given argument is a non-zero int or not.
 * numeric = 1
 * non-numeric = 0
 */


int ft_isdigit(int input)
{
    if (input >= 48 && input <= 57) // ascii: 48 = 0, 57 = 9
    {
        return 1;
    }
    return 0;
}
