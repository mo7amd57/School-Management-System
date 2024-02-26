#ifndef TC_H
#define TC_H

#include <stdio.h>



#define TC_NRM  "\x1B[0m"
#define TC_RED  "\x1B[1;31m"
#define TC_GRN  "\x1B[1;32m"
#define TC_YEL  "\x1B[1;33m"
#define TC_BLU  "\x1B[1;34m"
#define TC_MAG  "\x1B[1;35m"
#define TC_CYN  "\x1B[1;36m"
#define TC_WHT  "\x1B[1;37m"

#define TC_B_NRM  "\x1B[0m"
#define TC_B_RED  "\x1B[0;31m"
#define TC_B_GRN  "\x1B[0;32m"
#define TC_B_YEL  "\x1B[0;33m"
#define TC_B_BLU  "\x1B[0;34m"
#define TC_B_MAG  "\x1B[0;35m"
#define TC_B_CYN  "\x1B[0;36m"
#define TC_B_WHT  "\x1B[0;37m"
#define TC_B_BLA  "\x1b[30;47m"
#define TC_B_WB   "\033[30m"

#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"


#define TC_BRIGHT_BLACK "\x1b[90m"
#define TC_BRIGHT_RED "\x1b[91m"
#define TC_BRIGHT_GREEN "\x1b[92m"
#define TC_BRIGHT_YELLOW "\x1b[93m"
#define TC_BRIGHT_BLUE "\x1b[94m"
#define TC_BRIGHT_MAGENTA "\x1b[95m"
#define TC_BRIGHT_CYAN "\x1b[96m"
#define TC_BRIGHT_WHITE "\x1b[97m"

#define TC_ORANGE "\x1b[38;5;202m" // Custom color: Orange
#define TC_PINK "\x1b[38;5;206m"   // Custom color: Pink
#define TC_SKY_BLUE "\x1b[38;5;111m" // Custom color: Sky Blue
#define TC_GOLD "\x1b[38;5;220m"    // Custom color: Gold
#define TC_DARK_BLUE "\x1b[34m"


#define TC_DARK_BLACK "\x1b[30m"
#define TC_DARK_RED "\x1b[31m"
#define TC_DARK_GREEN "\x1b[32m"
#define TC_DARK_YELLOW "\x1b[33m"
#define TC_DARK_BLUE "\x1b[34m"
#define TC_DARK_MAGENTA "\x1b[35m"
#define TC_DARK_CYAN "\x1b[36m"
#define TC_DARK_WHITE "\x1b[37m"

#define tc_clear_screen() puts("\x1B[2J")

#define tc_move_cursor(X, Y) printf("\033[%d;%dH", Y, X)

void tc_get_cols_rows(int *cols, int *rows);

#define tc_enter_alt_screen() puts("\033[?1049h\033[H")
#define tc_exit_alt_screen() puts("\033[?1049l")

void tc_echo_off();
void tc_echo_on();



#endif
