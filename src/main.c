/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** bsq main
*/

#include <stddef.h>
#include "my.h"
#include "bsq.h"

static size_t usage(size_t exit_value, char const *exec_name)
{
    my_putstr("find the biggest square in a map\n\nUSAGE\n\t");
    my_putstr(exec_name);
    my_putstr("\t[OPTIONS] map_file_path\n\tmap_file_path\tfile path of the "
            "map to test.\n\nOPTIONS\n\t-h\tprint the usage and quit.\n");
    return exit_value;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return usage(EXIT_NOT_ENOUGH_ARGS, argv[0]);
    }
    if (!my_strcmp(argv[1], "-h"))
        return usage(EXIT_SUCCESS, argv[0]);
    return bsq_main(argv[1]);
}