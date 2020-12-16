#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "render.h"
#include "player.h"

void print_n(int y, int x, float n) {
    char buff[16];
    sprintf(buff, "%f", n);
    mvaddstr(y, x, buff);
}

void rotate_point(Point c, Point *p, double angle) {
    p->x = cos(angle) * (p->x - c.x) - sin(angle) * (p->y - c.y) + c.x;
    p->y = sin(angle) * (p->x - c.x) + cos(angle) * (p->y - c.y) + c.y;
}

void rotate_line(Point c, Line *l, double angle) {
    rotate_point(c, &l->p0, angle);
    rotate_point(c, &l->p1, angle);
}

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(WORLD_WIDTH/2, WORLD_HEIGHT/2, 0);
    Point o = POINT(WORLD_WIDTH/2 - 10, WORLD_HEIGHT/2 - 40);
    while (1) {
        clear();
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
