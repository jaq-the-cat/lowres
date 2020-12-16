#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "render.h"
#include "player.h"

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

void rotate_line(Point c, Line *l, double angle) {
    rotate_point(c, &l->p0, angle);
    rotate_point(c, &l->p1, angle);
}

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(WORLD_WIDTH/2, WORLD_HEIGHT/2, 0);
    Point o = POINT(WORLD_WIDTH/2, WORLD_HEIGHT/2 - 40);
    while (1) {
        clear();
        print_n(0, 0, p.origin.x);
        print_n(1, 0, p.origin.y);
        print_n(2, 0, o.x);
        print_n(3, 0, o.y);
        display_point(o.y, o.x, 'C');
        print_player(&p);
        refresh();
        getch();
        rotate_point(p.origin, &o, 0.2);
    }

    curs_set(1);
    endwin();
    return 0;
}
