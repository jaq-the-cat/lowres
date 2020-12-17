#include <stdlib.h>
#include <stdio.h>

#include "render.h"
#include "player.h"
#include "3d.h"

#define ROTATION 12

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(0, 0, 0);
    double movement_vec[2] = {0};

    Line wall = {
        POINT(-20, -40),
        POINT( 20, -40),
    };

    while (1) {
        clear();
        display_line(wall[0].y, wall[0].x, wall[1].y, wall[1].x);
        print_player(&p);
        refresh();
        movement_vec[0] = 0;
        movement_vec[1] = 0;
        switch (getch()) {
            case 'w':
                movement_vec[1] = 5;
                break;
            case 'q':
                movement_vec[0] = -5;
                break;
            case 's':
                movement_vec[1] = -5;
                break;
            case 'e':
                movement_vec[0] = 5;
                break;
            case 'd':
                rotate_line(p.origin, wall, RAD(-ROTATION));
                break;
            case 'a':
                rotate_line(p.origin, wall, RAD(ROTATION));
                break;
        }
        trans_line(wall, movement_vec);
    }

    curs_set(1);
    endwin();
    return 0;
}
