#include <stdlib.h>
#include <stdio.h>
#include "3d.h"
#include "render.h"

int main() {

    Point camera = P(0, 0, 0);
    float d = 10;

    Point p = P(0, 0, 50);
    float psx = p.x * (d / p.z);
    float psy = p.y * (d / p.z);

    initscr();

    clear();

    display_point(WORLD_HEIGHT/2 + psy, WORLD_HEIGHT/2 + psx);

    refresh();

    getch();
    endwin();

    printf("%f, %f\n", psx, psy);
    return 0;
}
