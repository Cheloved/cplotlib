#include "libs/drawing.h"

void drawAxis(float thickness, float r, float g, float b)
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

void drawGrid(float thickness, float step, float r, float g, float b, float alpha)
{
    glColor4f(r, g, b, alpha);

    glLineWidth(thickness);

    // Horizontal grids on top
    for ( float y = 0; y < HEIGHT/2+t_offset[1]; y += step )
    {
        glBegin(GL_LINES);
        glVertex2f(-WIDTH/2+t_offset[0], y);
        glVertex2f(WIDTH/2+t_offset[0], y);
        glEnd();
    }
    
    // Horizontal grids on bottom 
    for ( float y = 0; y > -HEIGHT/2+t_offset[1]; y -= step )
    {
        glBegin(GL_LINES);
        glVertex2f(-WIDTH/2+t_offset[0], y);
        glVertex2f(WIDTH/2+t_offset[0], y);
        glEnd();
    }
    
    // Vertical grids on the right side
    for ( float x = 0; x < WIDTH/2+t_offset[0]; x += step )
    {
        glBegin(GL_LINES);
        glVertex2f(x, -HEIGHT/2+t_offset[1]);
        glVertex2f(x, HEIGHT/2+t_offset[1]);
        glEnd();
    }
    
    // Vertical grids on the left side
    for ( float x = 0; x > -WIDTH/2+t_offset[0]; x -= step )
    {
        glBegin(GL_LINES);
        glVertex2f(x, -HEIGHT/2+t_offset[1]);
        glVertex2f(x, HEIGHT/2+t_offset[1]);
        glEnd();
    }
}

void drawCircle(float radius, float delta)
{
    float x, y;

    glPointSize(1.0);
      
    // Set draw color
    glColor3f(0.1, 0.1, 0.9);
      
    glBegin(GL_POINTS);
    for ( float i = 0; i < (2 * pi); i += delta)
    {
        x = radius * cos(i);
        y = radius * sin(i);
          
        glVertex2f(x, y);
    }
    glEnd();
}

