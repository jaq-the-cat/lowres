#ifndef THREED_H
#define THREED_H

#include <ncurses.h>
#include <math.h>
#include "render.h"

#define PI 3.14
#define RAD(deg) deg * (PI/180)
#define POINT(x, y) (Point) { WORLD_WIDTH/2 + (x), WORLD_HEIGHT/2 + (y) }
#define LINE(x0, y0, x1, y1) { POINT(x0, y0), POINT(x1, y1) }

typedef struct {
    double x, y;
} Point;

typedef Point Line[2];

void print_n(int y, int x, double n);
void rotate_point(Point c, Point *p, double angle);
void rotate_line(Point c, Line l, double angle);

#endif
