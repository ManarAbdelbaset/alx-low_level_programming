#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *str);
void _print_number(char *number);
void _multiply(char *num1, char *num2);
int _isdigit(char *str);
int main(int argc, char **argv);

#endif
