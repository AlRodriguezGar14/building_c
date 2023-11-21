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
#include "../bzero.c"
#include "../memcpy.c"



void print_pass_int(int original, int copy);
void print_fail_int(int original, int copy);
void print_test_title(char *title);
void    print_str_comparison(char *original, char *copy);

typedef int (*CharTypeChecker)(int);
typedef size_t (*CheckStringContent)(const char*);


typedef enum {
    MEMSET_FUNC,
    BZERO_FUNC,
    MEMCPY_FUNC
} StringManipulationFunction;


void string_manipulation_test(char* title, char** tests_a, char** tests_b, StringManipulationFunction func_type) {
    print_test_title(title);

    for (int i = 0; tests_a[i] != NULL; i++) {
        printf("Input: '%s' - ", tests_a[i]);

        char* a = malloc(ft_strlen(tests_a[i]) + 1);
        char* b = malloc(ft_strlen(tests_b[i]) + 1);
        strcpy(a, tests_a[i]);
        strcpy(b, tests_b[i]);

        switch (func_type) {
            case MEMSET_FUNC:
                memset(a, '*', sizeof(char) * i);
                ft_memset(b, '*', sizeof(char) * i);
                break;
            case BZERO_FUNC:
                bzero(a, sizeof(char) * i);
                ft_bzero(b, sizeof(char) * i);
                break;
            case MEMCPY_FUNC:
                memcpy(a, b, ft_strlen(b) + 1);
                ft_memcpy(b, a, ft_strlen(a) + 1);
                break;
            // Add cases for more functions
            default:
                // Handle unsupported function type
                break;
        }

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

    char *tests_a[] = {
        "Hello how are you doing?",
        "I'm using multipl€ ic0ns & numbers",
        "Add\tsome\ttabs",
        NULL
    };
    
    char *tests_b[] = {
        "Hello how are you doing?",
        "I'm using multipl€ ic0ns & numbers",
        "Add\tsome\ttabs",
        NULL
    };

    char *tests_c[] = {
        "Replacing the first",
        "Continu€ R€placing!!1!1",
        "replace\tfor\ttabs",
        NULL
    };

    // Char type functions
    test_different_char_types(&isdigit, &ft_isdigit, "Testing isdigit()");   
    test_different_char_types(&isalpha, &ft_isalpha, "Testing isalpha()");   
    test_different_char_types(&isalnum, &ft_isalnum, "Testing isalnum()");   
    test_different_char_types(&isascii, &ft_isascii, "Testing isascii()");   
    test_different_char_types(&isprint, &ft_isprint, "Testing isprint()");   


    // Test length
    test_string_content(&strlen, &ft_strlen, "Testing strlen()");

    // Manipulate content of strings
    string_manipulation_test("Testing memset()", tests_a, tests_b, MEMSET_FUNC);
    string_manipulation_test("Testing bzero()", tests_a, tests_b, BZERO_FUNC);
    string_manipulation_test("Testing memcpy()", tests_a, tests_c, MEMCPY_FUNC);

    return 0;
}
