#include <stdlib.h>
#include <stdio.h>
#include "render.h"

int main() {
    initscr();

    display_line(10, 10, 190, 490);
    refresh();

    getch();
    endwin();
    return 0;
}
