#ifndef FUNC_H
#define FUNC_H

#include <ncurses.h>
#include <math.h>
#include "3d.h"

#define PI 3.14
#define RAD(deg) deg * (PI/180)

void print_n(int y, int x, double n);
void rotate_point(Point c, Point *p, double angle);
void rotate_line(Point c, Line l, double angle);

#endif
