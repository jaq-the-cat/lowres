#include <stdlib.h>
#include <stdio.h>
#include "render.h"

int main() {
    initscr();

    for (int i=0; i<WORLD_HEIGHT; i++) {
        clear();
        display_line(WORLD_HEIGHT/2, 10, i, 490);
        refresh();
        napms(10);
    }

    endwin();
    return 0;
}
