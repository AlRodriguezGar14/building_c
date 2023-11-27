#include <unistd.h>
#include "../libft.h"


static int get_length(int n)
{
    int len;

    len = 1;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

static int get_operator(long n)
{
    int operator;

    operator = 1;
    while (n > 9)
    {
        n /= 10;
        operator *= 10;
    }
    return operator;
}

static void    write_number(int len, int simbol, long out_n, int operator, int fd)
{
    int idx;
    char to_print;

    idx = 0;
    if (simbol < 0)
    {
        write(fd, "-", 1);
    }
    while (idx < len - 1)
    {
        to_print = (out_n / operator) + '0';
        write(fd, &to_print, 1);
        out_n %= operator;
        operator /= 10;
        idx++;
    }
}

void ft_putnbr_fd(int n, int fd)
{
   int operator, len;
   long simbol, out_n;


    simbol = (n < 0) ? -1 : 1;

    out_n = n * simbol;

    operator = get_operator(out_n);
    len = get_length(operator);
    write_number(len, simbol, out_n, operator, fd);

}
