#include "func.h"

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
