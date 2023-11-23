// memmove it can copy forwars and backwards, while memcpy only works forward
// memmove is safer than memcpy because deals with overlapping buffers

#include <stdio.h>
#include <stdlib.h>


void *ft_memmove(void *dest, const void *src, size_t n)
{
    char *char_dest = (char *)dest;
    const char *char_src = (const char *)src;

    if (dest == NULL && src == NULL)
        return NULL;

    if (char_dest < char_src || char_dest >= (char_src + n))
    {
        // copy from start to end
        size_t idx = 0;
        while (idx < n)
        {
            char_dest[idx] = char_src[idx];
            idx++;
        }
    }
    else
    {
        // copy from end to start
        size_t idx = n;
        while (idx > 0)
        {
            char_dest[idx - 1] = char_src[idx - 1];
            idx--;
        }
    }

    return dest;
}

// void *ft_memmove(void *dest, const void *src, size_t n)
// {
//     char    *char_dest = (char *)dest;
//     char    *char_src = (char *)src;
//     char    *tmp = (char *)malloc(sizeof(char) * n);
//     
//     if (char_dest == char_src)
//         return char_dest;
//
//     if (tmp == NULL)
//     {
//         return NULL;
//     }
//
//     size_t     idx = 0;
//     while(idx < n)
//     {
//         tmp[idx] = char_src[idx];
//         idx++;
//     }
//
//     idx = 0;
//     while(idx < n)
//     {
//         char_dest[idx] = tmp[idx];
//         idx++;
//     }
//
//     free(tmp);
//
//     return dest;
// }

// this should be memcpy, but I'm having compiler errors
// try to replace it once it's converted to a library
// static void *copy(void *dest, void *src, size_t bytes_copied)
// {
//     int     idx = 0;
//     char    *char_dest = (char *)dest;
//     char    *char_src = (char *)src;
//
//     while (idx < bytes_copied)
//     {
//         char_dest[idx] = char_src[idx];
//         idx++;
//     }
//
//     return dest;
// }
//
// The logic of this code has been taken from: https://opensource.apple.com/source/network_cmds/network_cmds-481.20.1/unbound/compat/memmove.c.auto.html
// void *ft_memmove(void *dest, void *src, size_t n)
// {
//     char    *char_dest = (char *)dest;
//     char    *char_src = (char *)src;
//
//     int idx = 0;
//     
//     if (char_dest == char_src || n == 0)
//         return dest;
//
//     if (char_dest > char_src && char_dest - char_src < (int)n)
//     {
//         while (n--)
//             char_dest[n] = char_src[n]; 
//     } else if (char_src > char_dest && char_src - char_dest < (int)n) {
//         while (idx < n) {
//             char_dest[idx] = char_src[idx];
//             idx++;
//         }
//     } else {
//         copy(dest, src, n);
//     }
//
//     return dest;
// }

/*
The main idea of the logic is to choose if:
Copy in the addresses after dest.
Copy in the addresses before src.
Copy in the addresses after src.
Not copy because the address is the same == the content is the same.

Let's break it down with a visual example for each case:

1. No Overlapping (char_dest == char_src || n == 0):
If char_dest and char_src are the same or n is zero, there's no need to do anything. It returns the destination as-is.
2. Overlapping Scenario - Copy in Reverse (char_dest > char_src && char_dest - char_src < (int)n):
Visual Example:

scss
Copy code
+---------------------------------+
|           ... (other data)       |
+---------------------------------+
|           [char_dest]            |  (Starts at 0x0900)
+---------------------------------+
|           ... (overlapping)       |
|           [char_src]             |  (Starts at 0x1000)
+---------------------------------+
In this case, your code performs a reverse copy (char_dest[n] = char_src[n]) to avoid overwriting data. It starts from the end of the buffer and moves towards the beginning.

3. Overlapping Scenario - Copy Forwards (char_src > char_dest && char_src - char_dest < (int)n):
Visual Example:

scss
Copy code
+---------------------------------+
|           ... (other data)       |
+---------------------------------+
|           [char_dest]            |  (Starts at 0x0900)
+---------------------------------+
|           ... (overlapping)       |
|           [char_src]             |  (Starts at 0x1000)
+---------------------------------+
In this case, your code performs a forward copy (char_dest[idx] = char_src[idx]) to avoid overwriting data. It starts from the beginning of the buffer and moves towards the end.

4. Non-Overlapping Scenario:
If none of the above conditions are met, it means there is no potential overlap, and your code can use a non-overlapping copy function (e.g., memcpy or a custom copy function).
I hope this makes the logic clearer. Let me know if you have further questions or if there's anything specific you'd like to focus on!
*/
