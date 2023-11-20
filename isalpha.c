/*
* isalpha() function checks whether a character is an alphabet (a to z and A-Z) or not.
* If a character passed to isalpha() is an alphabet, it returns a non-zero integer, if not it returns 0.
* The received argumen is an integer
 */

int ft_isalpha(int character) {
    if ((character >= 65 && character <= 90) 
        || (character >= 97 && character <= 122))
    {
        return 1;
    }
    return 0;
}
