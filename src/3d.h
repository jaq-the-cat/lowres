#ifndef THREED_H
#define THREED_H

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p0, p1;
} Line;

#define POINT(x, y) (Point) { x, y }
#define LINE(x0, y0, x1, y1) { POINT(x0, y0), POINT(x1, y1) }

#endif
