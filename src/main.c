/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** bsq main
*/

#include "my.h"
#include "bsq.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    return bsq_main(argv[1]);
}