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

static int check_errors(int value, char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\0' && buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_put_error_str(MSG_FIRST_LINE_NOT_NUMBER);
            return EXIT_FIRST_LINE_NOT_NUMBER;
        }
    if (value < 0) {
        my_put_error_str(MSG_READ_FAIL);
        return EXIT_READ_FAIL;
    }
    if (value == 0) {
        my_put_error_str(MSG_READ_EMPTY_FILE);
        return EXIT_READ_EMPTY_FILE;
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
    tab = malloc(sizeof(char *) * (y + 2));
    if (tab == NULL || lines == NULL || y <= 0)
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

static off_t get_filesize(char *filepath)
{
    struct stat st;
    stat(filepath, &st);

    return st.st_size;
}

static int check_nbr_lines(char *buffer)
{
    int i = 0;
    int n = 0;
    int lines = 0;
    char *nbr_c;

    for (; buffer[i] != '\n'; i++);
    nbr_c = my_strndup(buffer, i);
    if (nbr_c == NULL)
        return EXIT_ERROR;
    lines = my_getnbr(nbr_c);
    for (i++; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            n++;
    if (n != lines) {
        free(nbr_c);
        my_put_error_str(MSG_INVALID_NBR_LINES);
        return EXIT_INVALID_NBR_LINES;
    }
    free(nbr_c);
    return 0;
}

int bsq_main(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (get_filesize(filepath) + 1));
    int size = read(fd, buffer, get_filesize(filepath));
    int error;

    close(fd);
    if (buffer == NULL) {
        my_put_error_str(MSG_ERROR);
        return EXIT_ERROR;
    }
    buffer[get_filesize(filepath)] = '\0';
    error = check_errors(size, buffer);
    if (error == 0)
        error = check_nbr_lines(buffer);
    if (error == 0 && get_squares(buffer, get_tab(buffer)) != 0) {
        my_put_error_str(MSG_ERROR);
        error = EXIT_ERROR;
    }
    free(buffer);
    return error;
}