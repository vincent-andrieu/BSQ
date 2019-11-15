/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find bigest square in a file
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "bsq.h"

static int get_square_size(char **tab, int y, int x, int n)
{
    for (int i = 0; i <= n; i++)
        if (tab[y + n] == NULL || tab[y + n][x + i] == '\0'
            || tab[y + n][x + i] != FULL_CHAR || tab[y + i][x + n] != FULL_CHAR)
            return n;
    return get_square_size(tab, y, x, ++n);
}

static void put_bigest_square(char *buffer, int n, int x, int y, int len)
{
    int i = 0;
    char *lines;

    for (; buffer[i] != '\n'; i++);
    lines = my_strndup(buffer, i);
    buffer += i + 1;
    for (int k = 0; k < n; k++)
        for (i = (y + k) * (len + 1) + x; i < (y + k) * (len + 1) + x + n; i++)
            buffer[i] = SQUARE_CHAR;
    write(1, buffer, my_getnbr(lines) * (len + 1));
    free(lines);
}

static void free_tabs(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

int get_squares(char *buffer, char **tab)
{
    int record = 0;
    int score;
    int x = 0;
    int y = 0;

    if (tab == NULL)
        return EXIT_ERROR;
    for (int i = 1; tab[i] != NULL; i++)
        for (int k = 0; tab[i][k] != '\0'; k++) {
            score = get_square_size(tab, i, k, 0);
            x = score > record ? k : x;
            y = score > record ? i : y;
            record = score > record ? score : record;
        }
    int len = my_strlen(tab[1]);
    put_bigest_square(buffer, record, x, y - 1, len);
    free_tabs(tab);
    return 0;
}