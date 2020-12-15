#include <stdlib.h>

#include "render.h"

int trans_c(float c, float max_world_c, float max_term_c) {
    return c / (max_world_c / max_term_c);
}

void plot_line(int x0, int y0, int x1, int y1) {
    int dx =  abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1-y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;  /* error value e_xy */
    int e2;
    while (1) {   /* loop */
        mvaddch(y0, x0, 'x');
        if (x0 == x1 && y0 == y1) break;
        e2 = 2*err;
        if (e2 >= dy) { /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) { /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        }
    }
}


void display_line(int y0, int x0, int y1, int x1) {
    int maxy, maxx;
    getmaxyx(stdscr, maxy,  maxx);

    y0 = trans_c(y0, WORLD_HEIGHT, maxy);
    x0 = trans_c(x0, WORLD_WIDTH, maxx);
    y1 = trans_c(y1, WORLD_HEIGHT, maxy);
    x1 = trans_c(x1, WORLD_WIDTH, maxx);

    plot_line(x0, y0, x1, y1);
}
