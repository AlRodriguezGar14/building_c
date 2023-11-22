#ifndef LIBFT
# define LIBFT

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int ft_isalnum(int c);
int ft_tolower(int c);
size_t ft_strlcat(char *dest, char *src, size_t dest_size);
void *ft_memchr(const void *str, int c, size_t n);
void *ft_memset(void *buffer, int val, unsigned long len);
void ft_bzero(void *buffer, unsigned long len);
void *ft_memmove(void *dest, const void *src, size_t n);
int ft_toupper(int c);
char *ft_strrchr(char *str, int c);
void *ft_calloc(int n_elements, int data_type);
int ft_isalpha(int c);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_isprint(int c);
unsigned long ft_strlen(const char *str);
char *ft_strdup(const char *str1);
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_isascii(int c);
char *ft_strnstr(const char *haystack, const char *needle, size_t loc);
int ft_isdigit(int c);
char *ft_strchr(const char *str, int c);
void *ft_memcpy(void *dest, void *src, size_t bytes_copied);
int ft_atoi(const char *str);

#endif
