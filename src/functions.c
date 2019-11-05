/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** functions file
*/

static int get_columns(char *buffer, int i, int n)
{
    for (; buffer[i] != '\n'; i++)
        if (buffer[i] == '\0') {
            my_putstr(MSG_NOT_ENOUGH_LINES);
            return EXIT_NOT_ENOUGH_LINES;
        }
    if (n < 1)
        get_columns(buffer, i, ++n);
    return i;
}

int *get_square_tab(char *buffer, int y)
{
    int x = get_columns(buffer, 0, 0);
    int squares[x > 0 ? x : 1][y];

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            squares[i][j] = 0;
    return squares;
}

bool is_split_char(char const c)
{
    if (c == '\n' || c == '\0')
        return true;
    return false;
}