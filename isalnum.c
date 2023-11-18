/*
 * Function to determine if the input is alphanumeric
 * is alphanumeric = 1
 * not alphanumeric = 0
 */


int fn_isalnum(int input)
{
    if ((input >= 48 && input <= 57)
        || (input >= 65 && input <= 90)
        || (input >= 97 && input <= 122))
    {
        return 1;
    }
    return 0;
}

