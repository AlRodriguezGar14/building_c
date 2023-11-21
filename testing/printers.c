#include <stdio.h>
#include <string.h>


#define COLOR_RED     "\x1b[38;5;176m"
#define COLOR_GREEN   "\x1b[38;5;78m"
#define COLOR_RESET   "\x1b[0m"
#define COLOR_YELLOW  "\x1b[38;5;178m"


void print_pass_str(char *original, char *copy)
{
    printf(COLOR_YELLOW"expected: %s, "COLOR_RESET, original);
    printf(COLOR_GREEN"result: %s. PASS\n"COLOR_RESET, copy);
}

void print_fail_str(char *original, char *copy)
{
    printf(COLOR_YELLOW"expected: %s, "COLOR_RESET, original);
    printf(COLOR_RED"result: %s. PASS\n"COLOR_RESET, copy);
}

void    print_str_comparison(char *original, char *copy)
{
    if (strcmp(original, copy) == 0) {
        print_pass_str(original, copy);
        return;
    }
    print_fail_str(original, copy);
}


void print_pass_int(int original, int copy)
{
    printf(COLOR_YELLOW"expected: %d, "COLOR_RESET, original);
    printf(COLOR_GREEN"result: %d. PASS\n"COLOR_RESET, copy);
}
void print_fail_int(int original, int copy)
{
    printf(COLOR_YELLOW"expected: %d, "COLOR_RESET, original);
    printf(COLOR_RED"result: %d. PASS\n"COLOR_RESET, copy);
}


void print_test_title(char *title) {
    printf("\n");
    int idx = 0;
    while (title[idx] != 0)
        idx++;

    while (idx > -4) 
    {
        idx--;
        printf("-");
    }
    printf("\n| ");
    idx = 0;
    while (title[idx] != 0)
    {
        printf("%c", title[idx]);
        idx++;
    }
    printf(" |\n");
    while (idx > -4)
    {
        idx--;
        printf("-");
    }
    printf("\n");
}


