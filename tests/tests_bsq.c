/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** tests criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "bsq.h"

Test(bsq_1, test_outputs) {
    cr_redirect_stdout();
    
    char *filepath = "maps/tests_maps_solved/intermediate_map_34_137_with_obstacles_25pc";
    struct stat st;
    stat(filepath, &st);
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * st.st_size);
    read(fd, buffer, st.st_size);
    
    close(fd);
    bsq_main("maps/tests_maps/intermediate_map_34_137_with_obstacles_25pc");
    cr_assert_stdout_eq_str(buffer);
    free(buffer);
}

Test(bsq, test_outputs_no_number_file) {
    cr_redirect_stderr();
    
    bsq_main("maps/tests_maps/map_no_number");
    cr_assert_stderr_eq_str("First line isn't a number\n");
}

Test(bsq, test_outputs_empty_file) {
    cr_redirect_stderr();
    
    bsq_main("maps/tests_maps/map_empty");
    cr_assert_stderr_eq_str("Empty file\n");
}

Test(bsq, test_outputs_read_failure) {
    cr_redirect_stderr();
    
    bsq_main("");
    cr_assert_stderr_eq_str("Read failed\n");
}

Test(bsq, test_outputs_invalid_number_lines) {
    cr_redirect_stderr();
    
    bsq_main("maps/tests_maps/map_invalid_nbr_lines");
    cr_assert_stderr_eq_str("Invalid number of lines\n");
}