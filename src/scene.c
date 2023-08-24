#include "libs/scene.h"

void move(float x, float y)
{
    t_offset[0] += x;
    t_offset[1] += y;
    glTranslatef(-x, -y, 0.0f);
}
