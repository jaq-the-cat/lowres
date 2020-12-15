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
        draw_quad(p0, p1, p2, p3, cam);
        p0.x += -10;
        p1.x += -10;
        p2.x += -10;
        p3.x += -10;
        refresh();
        getch();
    }

    curs_set(1);
    endwin();
    return 0;
}
