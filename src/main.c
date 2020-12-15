#include <stdlib.h>
#include <stdio.h>
#include "3d.h"
#include "render.h"

void print_n(int y, int x, float n) {
    char buff[16];
    sprintf(buff, "%f", n);
    mvaddstr(y, x, buff);
}

int main() {

    Point camera = P(0, 0, 0);
    float d = 10;
    Point p0 = P(-20, 0, 200);
    Point p1 = P(20, 0, 200);

    initscr();
    curs_set(0);

    float p0sx, p0sy;
    float p1sx, p1sy;
    for (int i=0; i<100; i++) {
        d+=2;
        p0sx = p0.x * (d / p0.z);
        p0sy = p0.y * (d / p0.z);
        p1sx = p1.x * (d / p1.z);
        p1sy = p1.y * (d / p1.z);

        clear();
        display_point(WORLD_HEIGHT/2 + p0sy, WORLD_WIDTH/2 + p0sx);
        display_point(WORLD_HEIGHT/2 + p1sy, WORLD_WIDTH/2 + p1sx);
        refresh();
        napms(30);
    }

    curs_set(1);
    endwin();
    return 0;
}
