#include <stdlib.h>
#include <stdio.h>

#include "player.h"
#include "3d.h"

#define ROTATION 12

#define WALLS 2

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(0, 0, 0);
    double movement_vec[2] = {0};

    Line walls[WALLS] = {
        LINE(
            -20, -40,
            20, -40
        ),
        LINE(
            20, -40,
            20, 0
        ),
    };

    int i;
    while (1) {
        clear();
        for (i=0; i<WALLS; i++)
            display_wall(walls[i]);
        print_player(&p);
        refresh();
        movement_vec[0] = 0;
        movement_vec[1] = 0;
        switch (getch()) {
            case 'w':
                movement_vec[1] = -5;   // UP
                break;
            case 'q':
                movement_vec[0] = -5;   // LEFT
                break;
            case 's':
                movement_vec[1] = 5;    // DOWN
                break;
            case 'e':
                movement_vec[0] = 5;    // RIGHT
                break;
            case 'd':                   // TURN LEFT
                for (i=0; i<WALLS; i++)
                    rotate_line(p.origin, walls[i], RAD(-ROTATION));
                break;
            case 'a':                   // TURN RIGHT
                for (i=0; i<WALLS; i++)
                    rotate_line(p.origin, walls[i], RAD(ROTATION));
                break;
        }
        for (i=0; i<WALLS; i++)
            trans_line(walls[i], movement_vec);
    }

    curs_set(1);
    endwin();
    return 0;
}
