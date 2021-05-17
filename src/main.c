#include <stdlib.h>
#include <stdio.h>

#include "3d.h"

#define ROTATION 12

#define WALLS 3

#define TOP 40
#define BOTTOM 40

#define LEFT -20
#define RIGHT 20


int main() {
    initscr();
    curs_set(0);

    int rotation = 0;

    Line walls[WALLS] = {
        LINE(
            LEFT, 0, 10,
            RIGHT, 0, 10
        )
    };

    int i;
    while (1) {
        clear();
        refresh();
        switch (getch()) {
            case 'd':                   // TURN LEFT
                for (i=0; i<WALLS; i++)
                    rotate_line(POINT(0, 0, 0), walls[i], RAD(-ROTATION));
                break;
            case 'a':                   // TURN RIGHT
                for (i=0; i<WALLS; i++)
                    rotate_line(POINT(0, 0, 0), walls[i], RAD(ROTATION));
                break;
        }
    }

    curs_set(1);
    endwin();
    return 0;
}
