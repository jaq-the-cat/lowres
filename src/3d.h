#ifndef THREED_H
#define THREED_H

typedef struct {
    int x, y, z;
} Point;

#define P(x, y, z) (Point) { WORLD_WIDTH/2+(x), WORLD_HEIGHT/2+(y), z}

#endif
