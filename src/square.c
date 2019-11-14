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
        return get_columns(buffer, i + 1, ++n);
    return i;
}

static int get_square_size(char **tab, int y, int x, int n)
{
    for (int i = 0; i <= n; i++)
        if (tab[y + n] == NULL || tab[y + n][x + i] == '\0'
            || tab[y + n][x + i] != FULL_CHAR || tab[y + i][x + n] != FULL_CHAR)
            return n;
    return get_square_size(tab, y, x, ++n);
}

static void put_bigest_square(char **tab, int n, int x, int y)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            tab[i][j] = SQUARE_CHAR;
    for (int i = 1; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

static void get_bigest_square(char **tab, int **squares)
{
    int record = 0;
    int x = 0;
    int y = 0;

    for (int i = 1; squares[i] != NULL; i++)
        for (int j = 0; squares[i][j] != -1; j++) {
            x = squares[i][j] > record ? i : x;
            y = squares[i][j] > record ? j : y;
            record = squares[i][j] > record ? squares[i][j] : record;
        }
    put_bigest_square(tab, squares[x][y], x, y);
}

int get_squares(char *buffer, char **tab)
{
    int x = get_columns(buffer, 0, 0) - my_strlen(tab[0]) - 1;
    int y = my_getnbr(tab[0]);
    int **squares = malloc(sizeof(int *) * (y + 2));

    if (tab == NULL || squares == NULL)
        return EXIT_ERROR;
    if (x <= 0)
        return EXIT_NOT_ENOUGH_LINES;
    for (int i = 0; i <= y; i++) {
        squares[i] = malloc(sizeof(int) * (x + 1));
        if (squares[i] == NULL)
            return EXIT_ERROR;
    }
    squares[y + 1] = NULL;
    for (int j = 1; j <= y; j++)
        squares[j][x] = -1;
    for (int i = 1; tab[i] != NULL; i++)
        for (int k = 0; tab[i][k] != '\0'; k++)
            squares[i][k] = get_square_size(tab, i, k, 0);
    get_bigest_square(tab, squares);
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
        free(squares[i]);
    }
    free(tab);
    free(squares);
    return 0;
}