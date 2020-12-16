#include <stdlib.h>
#include <stdio.h>

#include "render.h"
#include "player.h"
#include "3d.h"

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(0, 0, 0);
    Line wall = {
        POINT(-20, -40),
        POINT( 20, -40),
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
