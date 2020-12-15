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

    initscr();

    for (int i=0; i<WORLD_HEIGHT; i++) {
        clear();
        refresh();
        napms(50);
    }

    endwin();
    return 0;
}
