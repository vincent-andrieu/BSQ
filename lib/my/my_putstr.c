/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print a string
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
