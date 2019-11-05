/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find bigest square in a file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "bsq.h"

static int get_columns(char *buffer, int i, int n)
{
    for (; buffer[i] != '\n'; i++)
        if (buffer[i] == '\0') {
            my_putstr(MSG_NOT_ENOUGH_LINES);
            return -1;
        }
    if (n < 1)
        get_columns(buffer, i, ++n);
    return i;
}

static int get_square_size(char **tab, int x, int y, int n)
{
    for (int i = 0; i < n && i < n; i++)
        if (tab[x + i][y] != FULL_CHAR || tab[x][y + i] != FULL_CHAR)
            return n;
    return get_square_size(tab, x, y, ++n);
}

static void put_bigest_square(char **tab, int n, int x, int y)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            tab[x][y] = SQUARE_CHAR;
    for (int i = 0; tab[i] != NULL; i++)
        my_putstr(tab[i]);
}

static void get_bigest_square(char **tab, int **squares)
{
    int record = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; squares[i] != NULL; i++)
        for (int j = 0; squares[i][j] != -1; j++) {
            x = squares[i][j] > record ? i : x;
            y = squares[i][j] > record ? j : y;
        }
    put_bigest_square(tab, squares[x][y], x, y);
}

int get_squares(char *buffer)
{
    char **tab = my_str_to_array(buffer, &is_split_char, false);
    int x = get_columns(buffer, 0, 0);
    int y = my_getnbr(tab[0]);
    int squares[x > 0 ? x + 1 : 1][y];

    if (tab == NULL)
        return EXIT_ERROR;
    if (x <= 0)
        return EXIT_NOT_ENOUGH_LINES;
    for (int i = 0; i <= x; i++)
        for (int j = 0; j < y; j++)
            squares[i][j] = i == x ? -1 : 0;
    for (int i = 0; tab[i] != NULL; i++)
        for (int k = 0; tab[i][k] != '\0'; k++) {
            squares[i][k] = get_square_size(tab, i, k, 0);
        }
    get_bigest_square(tab, squares);
    return 0;
}