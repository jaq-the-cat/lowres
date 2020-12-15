#ifndef THREED_H
#define THREED_H

typedef struct {
    int x, y, z;
} Point;

typedef Point Quad[4];

#define P(x, y, z) (Point) { WORLD_WIDTH/2+(x), y, z}

#endif
