/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the bigest square in an array
*/

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"

bool is_split_char(char const c)
{
    if (c == '\n' || c == '\0')
        return true;
    return false;
}

static int check_errors(int value, char *buffer, int size)
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
        my_putstr(MSG_READ_EMPTY_FILE);
        return EXIT_READ_EMPTY_FILE;
    }
    if (value < size) {
        my_putstr(MSG_READ_NOT_COMPLETE);
        return EXIT_READ_NOT_COMPLETE;
    }
    return 0;
}

static int bsq_main(filepath)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open(filepath, O_RDONLY);
    char buffer[st.st_size];
    int size = read(fd, buffer, st.st_size);

    close(fd);
    if (check_errors(size, buffer, st.st_size) != 0)
        return check_errors(size, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    if (get_squares(buffer) != 0) {
        my_putstr(MSG_ERROR);
        return EXIT_ERROR;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 1) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    return bsq_main(argv[1]);
}