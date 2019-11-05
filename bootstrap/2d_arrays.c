/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** return a positive number on the first line
*/

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int n = 0;

    for (int i = 0; i < nb_cols; i++)
        for (int k = 0; k < nb_rows; k++)
            if (arr[i][k] == number)
                n++;
    return n;
}