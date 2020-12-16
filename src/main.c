#include <stdlib.h>
#include <stdio.h>

#include "render.h"
#include "player.h"

void print_n(int y, int x, float n) {
    char buff[16];
    sprintf(buff, "%f", n);
    mvaddstr(y, x, buff);
}

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(WORLD_WIDTH/2, WORLD_HEIGHT/2, 0);
    Line wall = LINE(
            WORLD_WIDTH/2 - 10, WORLD_HEIGHT/2 - 10,
            WORLD_WIDTH/2 + 10, WORLD_HEIGHT/2 - 10
            );

    while (1) {
        clear();
        display_line(wall.p0.y, wall.p0.x, wall.p1.y, wall.p1.x);
        print_player(&p);
        refresh();
        getch();
    }

    curs_set(1);
    endwin();
    return 0;
}
