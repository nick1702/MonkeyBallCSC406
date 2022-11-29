//
//  main.cpp
//  MonkeyBall
//
//  Created by Nicholas Powers on 11/29/22.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>
//
#include "glPlatform.h"
#include "ApplConstants.h"
//
using namespace shapes2d;

using namespace std;

//    Prototypes for my local functions.
void drawReferenceFrame(void);
void setMaterial(GLfloat ambRed, GLfloat ambGreen, GLfloat ambBlue, GLfloat difRed,
                 GLfloat difGreen, GLfloat difBlue, GLfloat specRed, GLfloat specGreen,
                 GLfloat specBlue, GLfloat shine);
void drawReferenceFrame(void);
void drawOrbit(void);
void cameraToWorld(void);
void setupCamera(void);
void myDisplay(void);
void myResize(int w, int h);
void myMouse(int b, int s, int x, int y);
void myKeyboard(unsigned char c, int x, int y);
void myTimeOut(int dt);
void myInit(void);

//  Current dimensions of the window
int gWindowWidth = 900,
    gWindowHeight = 900;
    


//WORLD DATA
const float World2D::X_MIN = -10, World2D::X_MAX = +10;
const float World2D::Y_MIN = -10, World2D::Y_MAX = +10;

const float World2D::WORLD_WIDTH = World2D::X_MAX - World2D::X_MIN;
const float World2D::WORLD_HEIGHT = World2D::Y_MAX - World2D::Y_MIN;


//    This is the function that does the actual scene drawing
//
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    //    We were drawing into the back buffer, now it should be brought
    //    to the forefront.
    glutSwapBuffers();
}

//    This callback function is called when the window is resized
//    (generally by the user of the application).
//
void myResize(int w, int h)
{
    //    update projection transformations
    glViewport(0, 0, w, h);
    
    //    When it's done, request a refresh of the display
    glutPostRedisplay();
}


//    This function is called when a mouse event occurs.  This event, of type s
//    (up, down, dragged, etc.), occurs on a particular button of the mouse.
//
void myMouse(int b, int s, int x, int y)
{
    switch (b)
    {
        case GLUT_LEFT_BUTTON:
            if (s == GLUT_DOWN)
            {
                //    do something
            }
            else if (s == GLUT_UP)
            {
                // do something else

            }
            break;

        case GLUT_MIDDLE_BUTTON:
            if (s == GLUT_DOWN)
            {
                //    do something
            }
            else if (s == GLUT_UP)
            {
                // do something else
            }
            break;

        case GLUT_RIGHT_BUTTON:
            if (s == GLUT_DOWN)
            {
                //    do something
            }
            else if (s == GLUT_UP)
            {
                // do something else
            }
            break;

        default:
            break;
    }
}

//    This callback function is called when a keyboard event occurs
//
void myKeyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 27:
            exit(0);
            break;
            
        default:
            break;
    }
}


//    This function is called after (at least) the specified time has ellapsed
//    since it was last "primed" (pushed back on the queue).
//
void myTimeOut(int dt)
{
    
    //    Set up next timer event
    glutTimerFunc(20, myTimeOut, 0);
}


void myInit(void)
{
    
    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(World2D::X_MIN, World2D::X_MAX, World2D::Y_MIN, World2D::Y_MAX);
    myDisplay();
}


int main(int argc, char** argv)
{
    //    Initialize glut and create a new window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(gWindowWidth, gWindowHeight);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Monkey Ball");
    glViewport(0, 0, 400, 300);
    
    //    set up the callbacks
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myResize);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(10, myTimeOut, 0);
    
    //    Now we can do application-level
    myInit();

    //    Now we enter the main loop of the program and to a large extend
    //    "loose control" over its execution.  The callback functions that
    //    we set up earlier will be called when the corresponding event
    //    occurs
    glutMainLoop();
    
    //    This will never be executed (the exit point will be in one of the
    //    call back functions).
    return 0;
}
