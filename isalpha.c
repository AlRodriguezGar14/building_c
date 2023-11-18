/*
* isalpha() function checks whether a character is an alphabet (a to z and A-Z) or not.
* If a character passed to isalpha() is an alphabet, it returns a non-zero integer, if not it returns 0.
* The received argumen is an integer
 */

#include <stdio.h>

int fn_isalpha(int character) {
    if ((character >= 65 && character <= 90) 
        || (character >= 97 && character <= 122))
    {
        return 1;
    }
    return 0;
}

int main() {
    printf("The output for 'b' is (1 is alpha, 0 no): %d\n", fn_isalpha('b'));
    printf("The output for '[' is (1 is alpha, 0 no): %d\n", fn_isalpha('['));
    return 0;
}
