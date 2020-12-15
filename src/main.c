#include <stdlib.h>
#include <stdio.h>
#include "render.h"

void print_n(int y, int x, float n) {
    char buff[16];
    sprintf(buff, "%f", n);
    mvaddstr(y, x, buff);
}

int main() {
    initscr();
    curs_set(0);


    while (1) {
        clear();
        refresh();
        getch();
    }

    curs_set(1);
    endwin();
    return 0;
}
