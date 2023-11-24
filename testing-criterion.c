#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"


// gcc testing-criterion.c libft.a -o testing-criterion -lcriterion


Test(learn_testing, ft_strnstr) {
    const char *original = "abcabc";
    const char *substring = "abc";
    size_t size = 6;

    const char *criterion_result = strnstr(original, substring, size);
    const char *custom_result = ft_strnstr(original, substring, size);

    cr_log_info("expected %s", criterion_result);
    cr_log_info("actual %s", criterion_result);

    cr_expect_eq(criterion_result, custom_result);
}


