#ifndef H_MOUSE
#define H_MOUSE

#include <GL/glut.h>
#include <stdio.h>

#include "scene.h"

extern float t_offset[2];

void event_mouse_click(int button, int state, int x, int y);
void event_mouse_motion(int x, int y);

#endif
