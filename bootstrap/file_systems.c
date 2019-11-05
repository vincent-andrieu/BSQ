/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find a square in a file
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        my_putstr("SUCCESS\n");
    else
        my_putstr("FAILURE\n");
    close(fd);
    return fd;
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int value = read(0, buffer, size);

    if (value == -1) {
        my_putstr("read failed\n");
        return;
    }
    if (value == 0) {
        my_putstr("read has nothing more to read\n");
        return;
    }
    if (value < size)
        my_putstr("read didn't complete the entire buffer\n");
    if (value == size)
        my_putstr("read completed the entire buffer\n");
    close(fd);
}

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    int size = read(fd, buffer, 500);

    if (size != 500)
        return;
    buffer[500] = '\0';
    my_putstr(buffer);
    close(fd);
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[x];
    int size = read(fd, buffer, x);

    if (size != x)
        return;
    my_putstr(buffer);
    close(fd);
}

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[2048];
    int size = read(fd, buffer, 2048);

    if (size <= 0)
        return;
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
    close(fd);
}