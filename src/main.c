/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the bigest square in an array
*/

#include <stdbool.h>
#include "my.h"
#include "bsq.h"

static int check_errors(int value, char *buffer)
{
    for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_putstr(MSG_FIRST_LINE_NOT_NUMBER);
            return EXIT_FIRST_LINE_NOT_NUMBER;
        }
    if (value == -1) {
        my_putstr(MSG_READ_FAIL);
        return EXIT_READ_FAIL;
    }
    if (value == 0) {
        my_putstr(MSG_READ_EMPTY);
        return EXIT_READ_EMPTY;
    }
    if (value < size) {
        my_putstr(MSG_READ_NOT_COMPLETE);
        return EXIT_READ_NOT_COMPLETE;
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open(argv[1], O_RDONLY);
    char buffer[st.st_size];
    int size = read(fd, buffer, st.st_size);

    close(fd);
    if (check_errors(size, buffer) != 0)
        return check_errors(size, buffer);
    if (get_squares(buffer) != 0) {
        my_putstr(MSG_ERROR);
        return EXIT_ERROR;
    }
}