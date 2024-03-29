#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#include <GL/glut.h>

#include "libs/defines.h"
#include "libs/drawing.h"
#include "libs/mouse.h"
#include "libs/scene.h"

// Set translation offset to zero
double t_offset[2] = {0.0, 0.0};
double scale = 50.0;

double f1(double x)
{
    return sin(x) + cos(3*x) + sin(9*x);
}

double f2(double x)
{
    return x*x;
}

double f3(double x)
{
    return exp(x);
}

void display (void) 
{
    // Clear everything
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxis(2.0, 0.7, 0.7, 0.7);
    drawGrid(1.0, 1.0, 0.3, 0.3, 0.3, 0.3);

    // Draw circle
    /* drawCircle(50, 0.01); */

    glColor3f(0.2, 0.2, 0.8);
    glLineWidth(2);
    drawFunc(&f1, -10, 10);

    glColor3f(0.8, 0.2, 0.2);
    glLineWidth(1);
    drawFunc(&f2, -10, 10);

    glColor3f(0.2, 0.8, 0.2);
    glLineWidth(3);
    drawFunc(&f3, -10, 10);

    // Update
    glutSwapBuffers();
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/MAX_FPS, timer, 0);
}

int main(int argc, char** argv)
{
    // Initialize OpenGL 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

    // Enable transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    // Set window size and position
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);

    // Set window name
    glutCreateWindow("CPlotLib");

    // Set background color
    glClearColor(0.1, 0.1, 0.1, 1.0);
      
    // Set size of a drawing point
    glPointSize(1.0);

    // Prepare matrix
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
      
    // Center the coordinates
    gluOrtho2D(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2);

    // Enable mouse callback
    glutMouseFunc(&event_mouse_click);
    glutMotionFunc(&event_mouse_motion);

    // Set random seed
    time_t t;
    srand((unsigned) time(&t));

    glutDisplayFunc(display);
    timer(0);

    glutMainLoop();

    return 0;
}
