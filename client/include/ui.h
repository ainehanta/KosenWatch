#ifndef __UI_H
#define __UI_H

#define TITLE_LOAD 0
#define TITLE_NEW  1
#define TITLE_LIST ((int[]){TITLE_LOAD, TITLE_NEW})
#define TITLE_LIST_LENGTH 2
#define MENU_BABA  0
#define MENU_BOMB  1
#define MENU_LIST  ((int[]){MENU_BABA, MENU_BOMB})
#define MENU_LIST_LENGTH 2
#define SELECT_YES 0
#define SELECT_NO  1
#define SELECT_LIST ((int[]){SELECT_YES, SELECT_NO})
#define SELECT_LIST_LENGTH 2

void print_title(void);
int print_menu(void);
int is_valid_input(int input, int* input_list, int length);
int get_input(int* input_list, int length);
int get_input_yes_no(void);
void print_array_literal(int* input_list, int length);

#endif
