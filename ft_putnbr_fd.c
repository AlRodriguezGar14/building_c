#include <unistd.h>
#include "libft.h"


int get_length(int n)
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

int get_operator(long n)
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


void ft_putnbr_fd(int n, int fd)
{
   char *printable;
   int idx;
   
   idx = 0;

   printable = ft_itoa(n);
   if (!printable) return;

   while(printable[idx])
   {
       write(fd, &printable[idx], 1);
       idx++;
   }
   free(printable);
}

int main(void)
{
    ft_putnbr_fd(-7654321, 1);
    return 0;
}
