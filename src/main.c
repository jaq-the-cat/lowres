#include <stdlib.h>
#include <stdio.h>

#include "player.h"
#include "3d.h"

#define ROTATION 12

#define WALLS 1

int main() {
    initscr();
    curs_set(0);
    
    Player p = PLAYER(0, 0, 0);
    double movement_vec[2] = {0};

    Line walls[WALLS] = {
        LINE(
            -20, -40,
            20, -40
        )
    };

    int i;
    while (1) {
        clear();
        print_player(&p);

        print_n(0, 0, walls[0][0].y);
        print_n(1, 0, walls[0][0].x);

        print_n(3, 0, walls[0][1].y);
        print_n(4, 0, walls[0][1].x);

        print_n(6, 0, p.origin.y);

        print_n(8, 0, p.origin.y - walls[0][0].y);
        for (i=0; i<WALLS; i++) {
            display_line(walls[i][0].y, walls[i][0].x, walls[i][1].y, walls[i][1].x);
            display_3d_line(walls[i], 30, p.origin.y - walls[i][0].y);
        }
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
