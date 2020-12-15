#include <stdlib.h>
#include <stdio.h>
#include "3d.h"
#include "render.h"

int main() {

    Point camera = P(0, 0, -10);
    Point p0 = P(-20, 10, 10);
    Point p1 = P(20, 10, 10);

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
