#include "libs/scene.h"

void move(double x, double y)
{
    t_offset[0] += x;
    t_offset[1] += y;
    glTranslated(-x, -y, 0.0);
}
