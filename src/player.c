#include <ncurses.h>

#include "player.h"
#include "render.h"

void print_player(Player *p) {
    display_point(p->origin.y, p->origin.x, 'O');
}
