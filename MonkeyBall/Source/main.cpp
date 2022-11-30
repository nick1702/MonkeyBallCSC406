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
void myDisplay(void);
void myResize(int w, int h);
void myMouse(int b, int s, int x, int y);
void myKeyboard(unsigned char c, int x, int y);
void myTimeOut(int dt);
void myInit(void);

//  Current dimensions of the window
int gWindowWidth = 1200,
    gWindowHeight = 900;
    





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

//     Allows to define the reflectance properties of the current object's material
void setMaterial(GLfloat ambRed, GLfloat ambGreen, GLfloat ambBlue, GLfloat difRed,
    GLfloat difGreen, GLfloat difBlue, GLfloat specRed, GLfloat specGreen,
    GLfloat specBlue, GLfloat shine)
{
    GLfloat ambient[4] = {ambRed, ambGreen, ambBlue, 1.f};
    GLfloat diffuse[4] = {difRed, difGreen, difBlue, 1.f};
    GLfloat specular[4] = {specRed, specGreen, specBlue, 1.f};
    GLfloat emission[4] = {0.f, 0.f, 0.f, 1.f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission);
    glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.f);
}

void drawReferenceFrame(void)
{
    glBegin(GL_LINES);
        //    Z --> red.
        glColor3f(1., 0., 0.);
        setMaterial(1.0, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(0., 0., -0.1);
        glVertex3f(0., 0., 0.5);
        //    X --> Blue
        setMaterial(0., 1.0, 0., 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(-0.1, 0., 0.);
        glVertex3f(0.5, 0., 0.);
        //    Y --> green
        setMaterial(0., 0., 1.0, 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(0., -0.1, 0.);
        glVertex3f(0., 0.5, 0.);
    glEnd();
}


void myInit(void)
{
    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.f, 4.f/3.f, 0.5f, 100.f);
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
