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

static void put_bigest_square(char *buffer, int *values, int len)
{
    int i = 0;
    char *lines;

    for (; buffer[i] != '\n'; i++);
    lines = my_strndup(buffer, i);
    buffer += i + 1;
    for (int k = 0; k < values[0]; k++)
        for (i = (values[2] - 1 + k) * (len + 1) + values[1];
        i < (values[2] - 1 + k) * (len + 1) + values[1] + values[0]; i++)
            buffer[i] = SQUARE_CHAR;
    write(1, buffer, my_getnbr(lines) * (len + 1));
    free(lines);
}

static void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

int get_squares(char *buffer, char **tab)
{
    int score;
    int values[3] = {0, 0, 0};
    int def_len = my_strlen(tab[1]);

    if (tab == NULL)
        return EXIT_ERROR;
    for (int i = 1; tab[i] != NULL; i++) {
        if (my_strlen(tab[i]) != def_len)
            return EXIT_ERROR;
        for (int k = 0; tab[i][k] != '\0'; k++) {
            score = get_square_size(tab, i, k, 0);
            values[1] = score > values[0] ? k : values[1];
            values[2] = score > values[0] ? i : values[2];
            values[0] = score > values[0] ? score : values[0];
        }
    }
    put_bigest_square(buffer, values, my_strlen(tab[1]));
    free_tab(tab);
    return 0;
}