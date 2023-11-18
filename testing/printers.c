#include <stdio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

void print_pass_int(int original, int copy)
{
    printf(COLOR_GREEN"expected: %d, result: %d. PASS\n"COLOR_RESET, original, copy);
}
void print_fail_int(int original, int copy)
{
    printf(COLOR_RED"expected: %d, result: %d. FAIL\n"COLOR_RESET, original, copy);
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


