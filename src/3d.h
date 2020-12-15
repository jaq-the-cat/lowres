#ifndef THREED_H
#define THREED_H

#include "render.h"

typedef struct {
    float x, y, z;
} Point;

void draw_3d_line(Point p0, Point p1, int d);
void draw_quad(Point p0, Point p1, Point p2, Point p3, Point cam);

#define P(x, y, z) (Point) {x, y, z}

#endif
