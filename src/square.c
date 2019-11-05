/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find bigest square in a file
*/

#include <stdbool.h>
#include "my.h"
#include "bsq.h"

static int get_square_size(char **tab, int x, int y, int n)
{
    for (int i = 0; i < n && i < n; i++)
        if (tab[x + i] != FULL_CHAR || tab[y + i] != FULL_CHAR)
            return n;
    return check_squares(tab, x, y, ++n);
}

int get_squares(char *buffer)
{
    char **tab = my_str_to_array(buffer, &is_split_char, false);
    int **squares = get_square_tab(buffer, my_getnbr(tab[0]));

    if (tab == NULL)
        return 84;
    for (int i = 0; tab[i] != NULL; i++)
        for (int k = 0; tab[i][k] != '\0'; k++) {
            squares[i][k] = get_square_size(tab, i, y, n);
        }
}