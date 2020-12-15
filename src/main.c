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
    initscr();
    curs_set(0);

    Point camera = P(0, 0, 0);
    float d = 10;
    Point p0 = P(-60, -20, 200);
    Point p1 = P( 60, -20, 200);
    Point p2 = P( 60,  20, 200);
    Point p3 = P(-60,  20, 200);

    for (int i=0; i<100; i++) {
        d+=2;
        clear();
        draw_3d_line(p0, p1, d);
        draw_3d_line(p1, p2, d);
        draw_3d_line(p2, p3, d);
        draw_3d_line(p3, p0, d);
        refresh();
        napms(30);
    }

    curs_set(1);
    endwin();
    return 0;
}
