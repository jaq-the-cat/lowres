#include "3d.h"

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

void trans_line(Line l, double v[2]) {
    for (int i=0; i<2; i++) {
        l[i].x -= v[0];
        l[i].y -= v[1];
    }
}

int trans_c(double c, double max_world_c, double max_term_c) {
    return c / (max_world_c / max_term_c);
}

void plot_line(int x0, int y0, int x1, int y1, char c) {
    int dx =  abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1-y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;  /* error value e_xy */
    int e2;
    while (1) {   /* loop */
        mvaddch(y0, x0, c);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2*err;
        if (e2 >= dy) { /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) { /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        }
    }
}

void display_point(int y, int x, char c) {
    int maxy, maxx;
    getmaxyx(stdscr, maxy,  maxx);

    y = trans_c(y, WORLD_HEIGHT, maxy);
    x = trans_c(x, WORLD_WIDTH, maxx);

    mvaddch(y, x, c);
}

void display_line(int y0, int x0, int y1, int x1) {
    int maxy, maxx;
    getmaxyx(stdscr, maxy,  maxx);

    y0 = trans_c(y0, WORLD_HEIGHT, maxy);
    x0 = trans_c(x0, WORLD_WIDTH, maxx);
    y1 = trans_c(y1, WORLD_HEIGHT, maxy);
    x1 = trans_c(x1, WORLD_WIDTH, maxx);

    plot_line(x0, y0, x1, y1, 'X');
}


void display_3d_line(Line line, int h, int d) {
    double p0y = WORLD_HEIGHT/2 - h + (1 * (d / line[0].y));
    double p0x = WORLD_WIDTH/2 + (line[0].x * (d / line[0].y));

    double p1y = WORLD_HEIGHT/2 - h + (1 * (d / line[1].y));
    double p1x = WORLD_WIDTH/2 + (line[1].x * (d / line[1].y));

    double p2y = WORLD_HEIGHT/2 + h + (1 * (d / line[1].y));
    double p2x = WORLD_WIDTH/2 + (line[1].x * (d / line[1].y));

    double p3y = WORLD_HEIGHT/2 + h + (1 * (d / line[1].y));
    double p3x = WORLD_WIDTH/2 + (line[0].x * (d / line[0].y));

    display_line(p0y, p0x, p1y, p1x);
    display_line(p1y, p1x, p2y, p2x);
    display_line(p2y, p2x, p3y, p3x);
    display_line(p3y, p3x, p0y, p0x);
}
