#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "render.h"
#include "player.h"

#define PI 3.14

#define RAD(deg) deg * (PI/180)

void print_n(int y, int x, double n) {
    char buff[16];
    sprintf(buff, "%fl", n);
    mvaddstr(y, x, buff);
}

void rotate_point(Point c, Point *p, double angle) {
    double oldx = p->x - c.x;
    double oldy = p->y - c.y;
    p->x = (oldx * cos(angle) - oldy * sin(angle)) + c.x;
    p->y = (oldx * sin(angle) + oldy * cos(angle)) + c.y;
}

void rotate_line(Point c, Line l, double angle) {
    rotate_point(c, &l[0], angle);
    rotate_point(c, &l[1], angle);
}

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(WORLD_WIDTH/2, WORLD_HEIGHT/2, 0);
    Line wall = {
        POINT(WORLD_WIDTH/2-20, WORLD_HEIGHT/2 - 40),
        POINT(WORLD_WIDTH/2+20, WORLD_HEIGHT/2 - 40),
    };
    while (1) {
        clear();
        display_line(wall[0].y, wall[0].x, wall[1].y, wall[1].x);
        print_player(&p);
        refresh();
        getch();
        rotate_line(p.origin, wall, RAD(12));
    }

    curs_set(1);
    endwin();
    return 0;
}
