#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../isalnum.c"
#include "../isalpha.c"
#include "../isdigit.c"
#include "../isascii.c"
#include "../isprint.c"
#include "../strlen.c"
#include "../memset.c"


void print_pass_int(int original, int copy);
void print_fail_int(int original, int copy);
void print_test_title(char *title);
void    print_str_comparison(char *original, char *copy);

typedef int (*CharTypeChecker)(int);
typedef size_t (*CheckStringContent)(const char*);
typedef void* (*MemSet)(void*, int, size_t);

void test_manipulate_string(MemSet original_func, MemSet my_func, char* title)
{
    print_test_title(title);
    char *tests_a[] = {
        "Hello how are you doing?",
        "I'm using multipl€ ic0ns & numbers",
        "Add\tsome\ttabs"
    };
    
    char *tests_b[] = {
        "Hello how are you doing?",
        "I'm using multipl€ ic0ns & numbers",
        "Add\tsome\ttabs"
    };

    for (int i = 0; i < sizeof(tests_a) / sizeof(tests_a[0]); i++) {
        printf("Input: '%s' - ", tests_a[i]);

        char *a = malloc(strlen(tests_a[i]) + 1);
        char *b = malloc(strlen(tests_b[i]) + 1);
        strcpy(a, tests_a[i]);
        strcpy(b, tests_b[i]);

        original_func(a, '*', sizeof(char)*i);
        my_func(b, '*', sizeof(char)*i);

        print_str_comparison(a, b);
        free(a);
        free(b);
    }
}

void test_string_content(CheckStringContent original_function, CheckStringContent my_function, char* title)
{
    print_test_title(title);

    char *tests[] = {
        "Hello World",
        "Numb3rs && Ch4rs",
        "Str\twith\ttabs"
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        int original= original_function(tests[i]);
        int copy = my_function(tests[i]);

        printf("Input: '%s' - ", tests[i]);
        if (original == copy)
            print_pass_int(original, copy);
        else
            print_fail_int(original,copy);
    }
}

void test_different_char_types(CharTypeChecker char_type_checker, CharTypeChecker my_checker, char *title)
{
    print_test_title(title);
    const char testing_chars[] = {
        '\x80',
        '\0',
        '+',
        '&',
        '0',
        ' ',
        'a',
        'B'
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
    // Char type functions
    test_different_char_types(&isdigit, &ft_isdigit, "Testing isdigit()");   
    test_different_char_types(&isalpha, &ft_isalpha, "Testing isalpha()");   
    test_different_char_types(&isalnum, &ft_isalnum, "Testing isalnum()");   
    test_different_char_types(&isascii, &ft_isascii, "Testing isascii()");   
    test_different_char_types(&isprint, &ft_isprint, "Testing isprint()");   


    // Test length
    test_string_content(&strlen, &ft_strlen, "Testing strlen()");

    // Manipulate content of strings
    test_manipulate_string(&memset, &ft_memset, "Testing memset()");
    return 0;
}
