#ifndef H_DRAWING
#define H_DRAWING

#include <GL/glut.h>
#include <math.h>

#include "defines.h"

void drawAxis(float thickness, float r, float g, float b);
void drawGrid(float thickness, float step, float r, float g, float b, float alpha);
void drawCircle(float radius, float delta);

#endif
