/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** put a file in a x y array
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "my.h"

static bool is_split_char(char const c)
{
    if (c == '\n')
        return true;
    return false;
}

char **file_to_array(char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open(filepath, O_RDONLY);
    char buffer[st.st_size];
    int size = read(fd, buffer, st.st_size);
    char **tab;

    if (size <= 0)
        return;
    close(fd);
    return my_str_to_array(buffer, &is_split_char, false);
}

int main(int argc, char **argv)
{
    argc++;
    char **tab = file_to_array(argv[1]);

    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}