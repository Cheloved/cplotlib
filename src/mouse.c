#include "libs/mouse.h"

int last_pos[2] = {0, 0};
char moving = 0;


void event_mouse_click(int button, int state, int x, int y)
{
    if ( button == 0 && state == GLUT_DOWN )
    {
        last_pos[0] = x;
        last_pos[1] = y;
        moving = 1;
    }

    if ( button == 0 && state == GLUT_UP )
        moving = 0;

    if ( button == 3 )
        scale *= 1.1;

    if ( button == 4 )
        scale *= 0.9;

    /* printf(" [DEBUG] Mouse click event:\n" \ */
    /*        "\tbutton: %d\n" \ */
    /*        "\tstate: %d\n" \ */
    /*        "\tx: %d\n" \ */
    /*        "\ty: %d\n", button, state, x, y); */
}

void event_mouse_motion(int x, int y)
{
    if ( moving )
    {
        move( last_pos[0] - x, y - last_pos[1]);
        last_pos[0] = x;
        last_pos[1] = y;
    }

    /* printf(" [DEBUG] Mouse motion event:\n" \ */
    /*        "\tx: %d\n" \ */
    /*        "\ty: %d\n", x, y); */
}

