/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq .h file
*/

#define MSG_READ_FAIL  "read failed\n"
#define EXIT_READ_FAIL 84
#define MSG_EMPTY_FILE "read has nothing more to read\n"
#define EXIT_EMPTY_FILE 84
#define MSG_READ_NOT_COMPLETE  "read didn't complete the entire buffer\n"
#define EXIT_READ_NOT_COMPLETE 84
#define MSG_NOT_ENOUGH_LINES  "Not enough lines\n"
#define EXIT_NOT_ENOUGH_LINES 84
#define MSG_FIRST_LINE_NOT_NUMBER "First line isn't a number\n"
#define EXIT_FIRST_LINE_NOT_NUMBER 84
#define MSG_ERROR "ERROR\n"
#define EXIT_ERROR 84

#define EMPTY_CHAR 'o'
#define FULL_CHAR '.'

void get_squares(char *buffer);
int *get_square_tab(char *buffer, int y);
bool is_split_char(char const c);