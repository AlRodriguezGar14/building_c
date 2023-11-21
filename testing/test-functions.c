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
#include "../memmove.c"



void print_pass_int(int original, int copy);
void print_fail_int(int original, int copy);
void print_test_title(char *title);
void    print_str_comparison(char *original, char *copy);

typedef int (*CharTypeChecker)(int);
typedef size_t (*CheckStringContent)(const char*);


typedef enum {
    MEMSET_FUNC,
    BZERO_FUNC,
    MEMCPY_FUNC,
    MEMMOVE_FUNC
} StringManipulationFunction;


void string_manipulation_test(char *title, char **tests_a, char **tests_b, StringManipulationFunction func_type) {
    print_test_title(title);

    for (int i = 0; tests_a[i] != NULL; i++) {
        printf("Input: '%s' - ", tests_a[i]);

        char *a = malloc(ft_strlen(tests_a[i]) + 1);
        char *b = malloc(ft_strlen(tests_b[i]) + 1);
        char *tmp_a = malloc(ft_strlen(tests_a[i]) + 1);
        char *tmp_b = malloc(ft_strlen(tests_b[i]) + 1);
        strcpy(a, tests_a[i]);
        strcpy(tmp_a, tests_a[i]);
        strcpy(b, tests_b[i]);
        strcpy(tmp_b, tests_b[i]);

        size_t len = ft_strlen(a);

        switch (func_type) {
            case MEMSET_FUNC:
                memset(a, '*', sizeof(char) * i);
                ft_memset(b, '*', sizeof(char) * i);
                print_str_comparison(a, b);
                break;
            case BZERO_FUNC:
                bzero(a, sizeof(char) * i);
                ft_bzero(b, sizeof(char) * i);
                print_str_comparison(a, b);
                break;
            case MEMCPY_FUNC:
                {
                    // Ensure that destination doesn't overlap with source
                    char *dest_tmp = malloc(len + 1);
                    memcpy(dest_tmp, tmp_b, len + 1);
                    ft_memcpy(a, b, len + 1);
                    print_str_comparison(dest_tmp, a);
                    free(dest_tmp);
                }
                break;
            case MEMMOVE_FUNC:
                memmove(tmp_a, tmp_b, 5);
                ft_memmove(a, b, 5);
                print_str_comparison(tmp_a, a);
                break;
            default:
                // Handle unsupported function type
                break;
        }

        free(a);
        free(b);
        free(tmp_a);
        free(tmp_b);
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
    string_manipulation_test("Testing memmove()", tests_a, tests_c, MEMMOVE_FUNC);

    return 0;
}
