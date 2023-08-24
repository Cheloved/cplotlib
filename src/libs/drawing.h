#ifndef H_DRAWING
#define H_DRAWING

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include<unistd.h>

#include "defines.h"

void drawAxis(double thickness, double r, double g, double b);
void drawGrid(double thickness, double step, double r, double g, double b, double alpha);
void drawCircle(double radius, double delta);
void drawFunc(double (*func)(double), double x1, double x2, double step);

#endif
