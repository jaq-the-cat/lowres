#include <stdlib.h>
#include <stdio.h>
#include "3d.h"
#include "render.h"

int to_screen(int pc, int pz, Point s) {
    return (pc * s.z) / pz;
}

int main() {

    Point camera = P(0, 0, 0);
    Point s = P(0, 0, 5);
    Point p0 = P(-10, -10, 20);
    Point p1 = P( 10,  10, 20);

    int sy0 = to_screen(p0.y, p0.z, s);
    int sx0 = to_screen(p0.x, p0.z, s);
    int sy1 = to_screen(p1.y, p1.z, s);
    int sx1 = to_screen(p1.x, p1.z, s);

    initscr();

    for (int i=0; i<WORLD_HEIGHT; i++) {
        clear();
        display_line(sy0, sx0, sy1, sx1);
        refresh();
        napms(50);
    }

    endwin();
    return 0;
}
