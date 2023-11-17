/*
 * This function determines if a given argument is a non-zero int or not.
 * numeric = 1
 * non-numeric = 0
 */

#include <stdio.h>

int fn_isdigit(int input)
{
    if (input > 48 && input <= 57) // ascii: 48 = 0, 57 = 9
    {
        return 1;
    }
    return 0;
}

int main() {
    printf("The output for 'b' is (1 is digit, 0 no): %d\n", fn_isdigit('b'));
    printf("The output for '7' is (1 is digit, 0 no): %d\n", fn_isdigit('7'));
    printf("The output for '0' is (1 is non-zero digit, 0 no): %d\n", fn_isdigit('0'));
    return 0;
}
