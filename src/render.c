#include "render.h"

int trans_c(float c, float max_world_c, float max_term_c) {
    return c / (max_world_c / max_term_c);
}

void display_line(int y0, int x0, int y1, int x1) {
    int maxy, maxx;
    getmaxyx(stdscr, maxy,  maxx);

    y0 = trans_c(y0, WORLD_HEIGHT, maxy);
    x0 = trans_c(x0, WORLD_WIDTH, maxx);
    y1 = trans_c(y1, WORLD_HEIGHT, maxy);
    x1 = trans_c(x1, WORLD_WIDTH, maxx);
}
