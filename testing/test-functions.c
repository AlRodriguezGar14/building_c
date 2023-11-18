#include <stdio.h>
#include <ctype.h>

#include "../isalnum.c"
#include "../isalpha.c"
#include "../isdigit.c"


void print_pass_int(int original, int copy);
void print_fail_int(int original, int copy);
void print_test_title(char *title);

typedef int (*CharTypeChecker)(int);

void test_different_char_types(CharTypeChecker char_type_checker, CharTypeChecker my_checker, char *title)
{
    print_test_title(title);
    const char testing_chars[] = {
        "1+&0 aB"
    };

    for (unsigned long i = 0; i < sizeof(testing_chars) - 1; ++i)
    {
        int original = char_type_checker(testing_chars[i]);
        int copy = my_checker(testing_chars[i]);
        
        printf("Input: '%c' - ", testing_chars[i]);
        if (original == copy)
            print_pass_int(original, copy);
        else
            print_fail_int(original,copy);
    }
}


int main()
{
    test_different_char_types(&isdigit, &fn_isdigit, "Testing isdigit()");   
    test_different_char_types(&isalpha, &fn_isalpha, "Testing isalpha()");   
    test_different_char_types(&isalnum, &fn_isalnum, "Testing isalnum()");   
    return 0;
}
