#include <stdio.h>
#include <ctype.h>

#include "../isalnum.c"


void print_pass_int(int original, int copy);
void print_fail_int(int original, int copy);
void print_test_title(char *title);


void test_isalnum()
{
    print_test_title("Testing isalnum()");
    const char testing_chars[] = {
        "2f& T0+"
    };

    for (unsigned long i = 0; i < sizeof(testing_chars) - 1; ++i)
    {
        int original = isalnum(testing_chars[i]);
        int copy = fn_isalnum(testing_chars[i]);
        
        printf("Input: '%c' - ", testing_chars[i]);
        if (original == copy)
            print_pass_int(original, copy);
        else
            print_fail_int(original,copy);
    }
}


int main()
{
    test_isalnum();   
    return 0;
}
