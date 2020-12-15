#include "render.h"

int trans_c(float c, float max_world_c, float max_term_c) {
    return c / (max_world_c / max_term_c);
}
