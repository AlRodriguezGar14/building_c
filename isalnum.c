/*
 * Function to determine if the input is alphanumeric
 * is alphanumeric = 1
 * not alphanumeric = 0
 */

#include <stdio.h>

int fn_isalnum(int input)
{
    if ((input >= 48 && input <= 57)
        || (input >= 65 && input <= 90)
        || (input >= 97 && input <= 122))
    {
        printf("\n%c is alphanumeric\n", input);
        return 1;
    }
    printf("\n%c is not alphanumeric\n", input);
    return 0;
}

int main()
{
    char i;

    printf("Enter an input: ");
    scanf("%c", &i);
    fn_isalnum(i);
    
    return 0;
}
