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

    Point cam = P(0, 0, 1);
    int w = 1600, h = 800;
    int xoff = 0, yoff = 0;
    Point p0  = P(-w/2 + xoff, -h/2 + yoff, 10);
    Point p1  = P( w/2 + xoff, -h/2 + yoff, 10);
    Point p2  = P( w/2 + xoff,  h/2 + yoff, 10);
    Point p3  = P(-w/2 + xoff,  h/2 + yoff, 10);

    while (1) {
        clear();
        draw_3d_line(p0, p1, cam.z);
        draw_3d_line(p1, p2, cam.z);
        draw_3d_line(p2, p3, cam.z);
        draw_3d_line(p3, p0, cam.z);
        p0.z -= 1;
        p1.z -= 1;
        refresh();
        getch();
    }

    curs_set(1);
    endwin();
    return 0;
}
