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
#include "../strlcpy.c"
#include "../strlcat.c"
#include "../toupper.c"
#include "../tolower.c"
#include "../strchr.c"
#include "../strrchr.c"



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
    MEMMOVE_FUNC,
    STRLCPY_FUNC,
    STRLCAT_FUNC,
    TOUPPER_FUNC,
    TOLOWER_FUNC,
    STRCHR_FUNC,
    STRRCHR_FUNC
} StringManipulationFunction;


void string_manipulation_test(char *title, char **tests_a, char **tests_b, StringManipulationFunction func_type) {
    print_test_title(title);

    for (int i = 0; tests_a[i] != NULL; i++) {
        printf("Inputs: '%s' | '%s' - ", tests_a[i], tests_b[i]);


        char *a = malloc(ft_strlen(tests_a[i]) + 1);
        char *b = malloc(ft_strlen(tests_b[i]) + 1);
        strcpy(a, tests_a[i]);
        strcpy(b, tests_b[i]);

        size_t len_a = ft_strlen(a);
        size_t len_b = ft_strlen(b);

        char *tmp_a = malloc(len_a + 1);
        char *tmp_b = malloc(len_b + 1);
        char *dest_tmp = malloc(len_a+ 1);
        char *src_tmp = malloc(len_b + 1);
        strcpy(tmp_a, tests_a[i]);
        strcpy(tmp_b, tests_b[i]);
        // Ensure that destination doesn't overlap with source
        strcpy(dest_tmp, tmp_a);
        strcpy(src_tmp, tmp_b);


        int return_a;
        int return_b;
        char *return_char_a;
        char *return_char_b;

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
                memcpy(dest_tmp, src_tmp, len_a + 1);
                ft_memcpy(a, b, len_a + 1);
                print_str_comparison(dest_tmp, a);
                break;
            case MEMMOVE_FUNC:
                memmove(dest_tmp, src_tmp, 13 - i);
                ft_memmove(a, b, 13 - i);
                print_str_comparison(dest_tmp, a);
                break;
            case STRLCPY_FUNC:
                return_a = strlcpy(dest_tmp, src_tmp, 13 - i);
                return_b = ft_strlcpy(a, b, 13 - i);
                // printf("return a: %d, return b: %d\n", return_a, return_b);
                print_str_comparison(dest_tmp, a);
                break;
            case STRLCAT_FUNC:
                strlcat(dest_tmp, src_tmp, strlen(dest_tmp) + 5);
                ft_strlcat(a, b, strlen(a) + 5);
                print_str_comparison(dest_tmp, a);
                break;
            case TOUPPER_FUNC:
                return_a = toupper(a[0]); 
                return_b = ft_toupper(b[0]);
                print_str_comparison((char*)&return_a, (char*)&return_b);
                break;
            case TOLOWER_FUNC:
                return_a = tolower(a[0]); 
                return_b = ft_tolower(b[0]);
                print_str_comparison((char*)&return_a, (char*)&return_b);
                break;
            case STRCHR_FUNC:
                return_char_a = strchr(a, 's'); 
                return_char_b = ft_strchr(b, 's');
                print_str_comparison(return_char_a, return_char_b);
                break;
            case STRRCHR_FUNC:
                return_char_a = strrchr(a, 's'); 
                return_char_b = ft_strrchr(b, 's');
                print_str_comparison(return_char_a, return_char_b);
                break;
            default:
                // Handle unsupported function type
                break;
        }

        free(a);
        free(b);
        free(tmp_a);
        free(tmp_b);
        free(dest_tmp);
        free(src_tmp);
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

    for (unsigned long i = 0; i < sizeof(testing_chars); ++i)
    {
        int original = char_type_checker(testing_chars[i]);
        int copy = my_checker(testing_chars[i]);
        
        printf("Inputs: '%c' - ", testing_chars[i]);
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
        "12232-,,,.fshaj\10k 43_-fd",
        "tabla\ttablao\ttab",
        "main short",
        NULL
    };
   // For same content 
    char *tests_b[] = {
        "Hello how are you doing?",
        "I'm using multipl€ ic0ns & numbers",
        "12232-,,,.fshaj\10k 43_-fd",
        "tabla\ttablao\ttab",
        "main short",
        NULL
    };
    // For different content
    char *tests_c[] = {
        "Replacing the first",
        "Continu€ R€placing!!1!1",
        "These\10 are more normal chars",
        "i like\ttabs\tabs",
        "the c options is much larger",
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
    string_manipulation_test("Testing strlcpy()", tests_a, tests_c, STRLCPY_FUNC);
    string_manipulation_test("Testing strlcat()", tests_a, tests_c, STRLCAT_FUNC);
    string_manipulation_test("Testing toupper()", tests_a, tests_b, TOUPPER_FUNC);
    string_manipulation_test("Testing tolower()", tests_a, tests_b, TOLOWER_FUNC);
    string_manipulation_test("Testing strchr()", tests_a, tests_b, STRCHR_FUNC);
    string_manipulation_test("Testing strrchr()", tests_a, tests_b, STRRCHR_FUNC);

    return 0;
}
