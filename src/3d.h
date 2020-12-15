#ifndef THREED_H
#define THREED_H

#include "render.h"

typedef struct {
    float x, y, z;
} Point;

void draw_3d_line(Point p0, Point p1, int d);

#define P(x, y, z) (Point) {x, y, z}

#endif
