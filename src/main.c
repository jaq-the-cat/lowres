#include <stdlib.h>
#include <stdio.h>

#include "func.h"
#include "render.h"
#include "player.h"

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
