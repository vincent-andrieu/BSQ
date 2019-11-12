/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the bigest square in an array
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"

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

static char **get_tab(char *buffer)
{
    char **tab;
    char *lines;
    int y;
    int i = 0;

    for (; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    lines = my_strndup(buffer, i);
    y = my_getnbr(lines);
    tab = malloc(sizeof(char *) * (y == NULL ? 0 : (y + 2)));
    if (tab == NULL || lines == NULL)
        return NULL;
    tab[0] = lines;
    tab[y + 1] = NULL;
    buffer += i + 1;
    for (i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    for (int k = 1; k <= y; k++) {
        tab[k] = my_strndup(buffer, i);
        buffer += i + 1;
    }
    return tab;
}

static int bsq_main(char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open(filepath, O_RDONLY);
    char buffer[st.st_size];
    int size = read(fd, buffer, st.st_size);
    int error = check_errors(size, buffer, st.st_size);

    close(fd);
    if (error != 0)
        return error;
    buffer[st.st_size] = '\0';
    if (get_squares(buffer, get_tab(buffer)) != 0) {
        my_putstr(MSG_ERROR);
        return EXIT_ERROR;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    return bsq_main(argv[1]);
}