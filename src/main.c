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

    Point cam= P(0, 0, 0);
    Point p0 = P(-60, -20, 100);
    Point p1 = P( 60, -20, 100);
    Point p2 = P( 60,  20, 100);
    Point p3 = P(-60,  20, 100);

    for (int i=0; i<100; i++) {
        cam.z+=2;
        clear();
        draw_3d_line(p0, p1, cam.z);
        draw_3d_line(p1, p2, cam.z);
        draw_3d_line(p2, p3, cam.z);
        draw_3d_line(p3, p0, cam.z);
        refresh();
        napms(30);
    }

    curs_set(1);
    endwin();
    return 0;
}
