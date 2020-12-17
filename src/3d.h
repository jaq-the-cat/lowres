#ifndef THREED_H
#define THREED_H

#include <ncurses.h>
#include <math.h>

#define WORLD_HEIGHT 180
#define WORLD_WIDTH 320

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
void trans_line(Line l, double v[2]);

int trans_c(double c, double max_world_c, double max_term_c);
void display_point(int y, int x, char c);
void display_line(int y0, int x0, int y1, int x1);

#endif
