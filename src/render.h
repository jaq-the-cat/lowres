#ifndef RENDER_H
#define RENDER_H

#include <ncurses.h>

#define WORLD_HEIGHT 320
#define WORLD_WIDTH 320

int trans_c(double c, double max_world_c, double max_term_c);
void display_point(int y, int x, char c);
void display_line(int y0, int x0, int y1, int x1);

#endif
