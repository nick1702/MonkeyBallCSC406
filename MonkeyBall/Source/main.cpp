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
void drawPlane(float width, float length);
void setupCamera(void);
void cameraToWorld(void);
void myDisplay(void);
void myResize(int w, int h);
void myMouse(int b, int s, int x, int y);
void myKeyboard(unsigned char c, int x, int y);
void myTimeOut(int dt);
void myInit(void);

//  Current dimensions of the window
int gWindowWidth = 1200,
    gWindowHeight = 900;

const float	FOV = 40;				//	camera's vertical field of view (in degree)

float		gFocalLength = 0.02,	//	the camera's focal length in meter.
			gNearZ = 0.0,			//	Position of the clipping planes along the camera's
			gFarZ = 100.0,			//		optical axis (Z axis)
			//
			gRoll = 0,			    //	Roll, pitch, yaw, and translation (Tx, Ty, Tz)
			gPitch =-90,		    //	  of the Camera--> World transformation
			gYaw = 0,
			gTx = 0,
			gTy = -5,
			gTz = -10;
    

//main members
#define USE_DISPLAY_LISTS    1
GLUquadric *cyl;



void setupCamera(void) {
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	float fovXY = 1.f*gWindowWidth/gWindowHeight;

	gluPerspective(FOV, fovXY, gNearZ, gFarZ);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
}

void cameraToWorld(void)
{
	glLoadIdentity();
	glTranslatef(gTx, gTy, gTz);
	glRotatef(gRoll, 0.0, 0.0, 1.0);
	glRotatef(gYaw, 0.0, 1.0, 0.0);
	glRotatef(gPitch, 1.0, 0.0, 0.0);
}

//    This is the function that does the actual scene drawing
//
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    //	Move from the camera to the world reference frame
	cameraToWorld();

    //drawReferenceFrame();

    drawPlane(10, 50);
    
    glPopMatrix();
    //    We were drawing into the back buffer, now it should be brought
    //    to the forefront.
    glutSwapBuffers();
}

void createDisplayLists(void)
{
//    torusList = glGenLists(1);
//    glNewList(torusList, GL_COMPILE);
//        setMaterial(0.2f, 0.9f, 0., 0.1f, 0.7f, 0.f, 0.1f, 0.5f, 0.f, 0.3f);
//        torus(12, 16, 1.5f, 0.3f);
//    glEndList();
//
//    glShadeModel(GL_FLAT);
//    glClearColor(0.0, 0.0, 0.0, 0.0);

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
        case 'w':
            gPitch += -1;
            cout << "Pitch = " << gPitch << endl;
            break;
        case 'a':
            gRoll += 1;
            cout << "Roll = " << gRoll << endl;
            break;
        case 's':
            gPitch += 1;
            cout << "Pitch = " << gPitch << endl;
            break;
        case 'd':
            gRoll += -1;
            cout << "Roll = " << gRoll << endl;
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
    glutPostRedisplay();
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

void drawPlane(float width, float length) {
    float HW = width/2;
    glBegin(GL_QUAD_STRIP);         //   1-----------------3
    glVertex3f(-HW, 0, 0);          //   |                 |
    glVertex3f(HW, 0, 0);           //   |                 |
    glVertex3f(-HW, length, 0);     //   |                 |
    glVertex3f(HW, length, 0);      //   2-----------------4
    glEnd();    
}

void myInit(void)
{
    setupCamera();
    
    #if USE_DISPLAY_LISTS
        createDisplayLists();
    #endif

    cyl = gluNewQuadric();
    gluQuadricDrawStyle(cyl, GLU_FILL);
    
    
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
