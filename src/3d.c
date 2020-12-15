#include "3d.h"

void draw_3d_line(Point p0, Point p1, int d) {
    float p0sx, p0sy;
    float p1sx, p1sy;
    p0sx = p0.x * (d / p0.z);
    p0sy = p0.y * (d / p0.z);
    p1sx = p1.x * (d / p1.z);
    p1sy = p1.y * (d / p1.z);
    display_line(
        WORLD_HEIGHT/2 + p0sy, WORLD_WIDTH/2 + p0sx,
        WORLD_HEIGHT/2 + p1sy, WORLD_WIDTH/2 + p1sx
    );
}
