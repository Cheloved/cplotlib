#include "libs/drawing.h"

void drawAxis(double thickness, double r, double g, double b)
{
    glColor3f(r, g, b);

    glLineWidth(thickness);

    // Horizontal
    glBegin(GL_LINES);
    glVertex2f(-WIDTH/2+t_offset[0], 0);
    glVertex2f(WIDTH/2+t_offset[0], 0);
    glEnd();
    
    // Vertical 
    glBegin(GL_LINES);
    glVertex2f(0, -HEIGHT/2+t_offset[1]);
    glVertex2f(0, HEIGHT/2+t_offset[1]);
    glEnd();
}

void drawGrid(double thickness, double step, double r, double g, double b, double alpha)
{
    glColor4f(r, g, b, alpha);

    glLineWidth(thickness);

    // Horizontal grids on top
    for ( double y = 0; y < HEIGHT/2+t_offset[1]; y += step )
    {
        glBegin(GL_LINES);
        glVertex2f(-WIDTH/2+t_offset[0], y);
        glVertex2f(WIDTH/2+t_offset[0], y);
        glEnd();
    }
    
    // Horizontal grids on bottom 
    for ( double y = 0; y > -HEIGHT/2+t_offset[1]; y -= step )
    {
        glBegin(GL_LINES);
        glVertex2f(-WIDTH/2+t_offset[0], y);
        glVertex2f(WIDTH/2+t_offset[0], y);
        glEnd();
    }
    
    // Vertical grids on the right side
    for ( double x = 0; x < WIDTH/2+t_offset[0]; x += step )
    {
        glBegin(GL_LINES);
        glVertex2f(x, -HEIGHT/2+t_offset[1]);
        glVertex2f(x, HEIGHT/2+t_offset[1]);
        glEnd();
    }
    
    // Vertical grids on the left side
    for ( double x = 0; x > -WIDTH/2+t_offset[0]; x -= step )
    {
        glBegin(GL_LINES);
        glVertex2f(x, -HEIGHT/2+t_offset[1]);
        glVertex2f(x, HEIGHT/2+t_offset[1]);
        glEnd();
    }
}

void drawCircle(double radius, double delta)
{
    double x, y;

    glPointSize(1.0);
      
    // Set draw color
    glColor3f(0.1, 0.1, 0.9);
      
    glBegin(GL_POINTS);
    for ( double i = 0; i < (2 * pi); i += delta)
    {
        x = radius * cos(i);
        y = radius * sin(i);
          
        glVertex2f(x, y);
    }
    glEnd();
}

void drawFunc(double (*func)(double), double x1, double x2, double step)
{
    double y = 0;

    /* glBegin(GL_LINES); */
    glBegin(GL_POINTS);
    for ( double x = -WIDTH/2+t_offset[0]; x < WIDTH/2+t_offset[0]; x += step )
    {
        y = func(x/scale);
        glVertex2f(x, y*scale);
    }
    glEnd();
}
