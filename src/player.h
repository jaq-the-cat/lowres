#ifndef PLAYER_H
#define PLAYER_H

#include "3d.h"
#include "render.h"

typedef struct  {
    Point origin;
    float rotation;
} Player;

#define PLAYER(x, y, r) (Player) { (Point) { x, y }, r }

#endif
