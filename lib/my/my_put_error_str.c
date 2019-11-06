/*
** EPITECH PROJECT, 2019
** my_put_error_str
** File description:
** print a char as error
*/

#include <unistd.h>

int my_put_error_str(char *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return 0;
}