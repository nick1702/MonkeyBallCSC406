/*==================================================================================+
#																					#
#	File:		main_1.cpp	 														#
#																					#
#	This small program demonstrates basic 3D rendering.								#
#																					#
#-----------------------------------------------------------------------------------#
#	Author:			jean-yves herve', Dept of CS, U. of Rhode Island				#
#																					#
#	Date Creation:	Fall 2021													#
#																					#
+==================================================================================*/

#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "glPlatform.h"
#include "Monkeyball.cpp"
#include "utils.hpp"
#include "test.cpp"
//
//	project-wide header for my telerobotics appl..  Lots of useless stuff for this test.
			
#define DEG_TO_RAD (3.14159 / 180)
#define RAD_TO_DEG 1/DEG_TO_RAD

using namespace std;
using namespace Monkey;

void setMaterial(GLfloat ambRed, GLfloat ambGreen, GLfloat ambBlue, GLfloat difRed,
            	 GLfloat difGreen, GLfloat difBlue, GLfloat specRed, GLfloat specGreen,
            	 GLfloat specBlue, GLfloat shine);
//	Prototypes for my local functions.
void drawReferenceFrame(void);
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


#define	kChipWidth	0.004	//	Width and height of my camera's CCD chip: 4mm and 3mm
#define	kChipHeight	0.003	//	tend to be fairly typical dimensions.
#define kSx			1.00	//	allows to model non-square grid of pixels.  Keep it to 1.


float		gRad = 0.6f,			//	Radius of the teapot's orbit
			gPosX = 0.6f,			//	position and orientation [around the X axis] of the
			gPosY = 0.f,			//		gluTeapot
			gPosZ = 0.5f,
			gAlpha = 0.f,
			gBeta = 0.f,
			gGamma = 0.f,
			//
			gFocalLength = 0.02,	//	the camera's focal length in meter.
			gNearZ = 10.0,			//	Position of the clipping planes along the camera's
			gFarZ = 30.0,			//		optical axis (Z axis)
			//
			gRoll = 0.0,			//	Roll, pitch, yaw, and translation (Tx, Ty, Tz)
			gPitch =-60,			//	  of the Camera--> World transformation
			gYaw = 10,
			gTx = 0.5,
			gTy = -0.5,
			gTz = -25,
			//
			gAlfaIncr = 1.f,		//	increments for angles alpha, beta, gamma
			gBetaIncr = 1.f,
			gGammaIncr = 1.f;
			//
short		gDrawMode = 0;
//
bool		gSmoothShading=true,
			gAnimate=true;	
int			winWidth = 1200, winHeight = 900;
bool		gDrawTeapot = false;


//	Move from the camera to the world reference frame:  Start from the camera and apply
//	a series of transformations to end up in the world reference frame, where the drawing
//	will take place
void cameraToWorld(void)
{
	glLoadIdentity();
	glTranslatef(gTx, gTy, gTz); 
	glRotatef(gRoll, 0.0, 0.0, 1.0);
	glRotatef(gYaw, 0.0, 1.0, 0.0);
	glRotatef(gPitch, 1.0, 0.0, 0.0);
}

void drawReferenceFrame(void)
{
    glBegin(GL_LINES);
        //  Z --> red.
        glColor3f(1., 0., 0.);
        setMaterial(1.0, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(0., 0., -0.1);
        glVertex3f(0., 0., 0.5);
        //  X --> Blue
        setMaterial(0., 1.0, 0., 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(-0.1, 0., 0.);
        glVertex3f(0.5, 0., 0.);
        //  Y --> green
        setMaterial(0., 0., 1.0, 0., 0., 0., 0., 0., 0., 0.);
        glVertex3f(0., -0.1, 0.);
        glVertex3f(0., 0.5, 0.);
    glEnd();
}

//	This is the function that does the actual scene drawing
float num = 0.0;
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	//	Move from the camera to the world reference frame
	cameraToWorld();

	//	Now I am in the world reference frame.
	//	I draw axes so that we can see what the local frame looks like.
	drawReferenceFrame();

    glPushMatrix();
        glTranslatef(ball->get_ox(), ball->get_oy(), ball->get_oz());
        drawReferenceFrame();
    glPopMatrix();
    setMaterial(1.0, 1.0, 1.0, 0., 0., 0., 0., 0., 0., 0.);

    update_test();

    //	save world reference frame
    glPushMatrix();

    //	back to world reference frame
    glPopMatrix();

    //	back to camera reference frame
    glPopMatrix();

    //	We were drawing into the back buffer, now it should be brought
    //	to the forefront.
    glutSwapBuffers();
}

//	This callback function is called when the window is resized
//	(generally by the user of the application).
//
void myResize(int w, int h)
{
    //	update projection transformations
    glViewport(0, 0, w, h);

    //	When it's done, request a refresh of the display
    glutPostRedisplay();
}


//	This function is called when a mouse event occurs.  This event, of type s
//	(up, down, dragged, etc.), occurs on a particular button of the mouse.
//
void myMouse(int b, int s, int x, int y)
{
    switch (b)
    {
        case GLUT_LEFT_BUTTON:
            if (s == GLUT_DOWN)
            {
                //	do something
            }
            else if (s == GLUT_UP)
            {
                // do something else
                gAlfaIncr *= -1.f;		//	invert alpha rotation
            }
            break;

        case GLUT_MIDDLE_BUTTON:
            if (s == GLUT_DOWN)
            {
                //	do something
            }
            else if (s == GLUT_UP)
            {
                // do something else
                gBetaIncr *= -1.f;		//	invert beta rotation
            }
            break;

        case GLUT_RIGHT_BUTTON:
            if (s == GLUT_DOWN)
            {
                //	do something
            }
            else if (s == GLUT_UP)
            {
                // do something else
                gGammaIncr *= -1.f;		//	invert gamma rotation
            }
            break;

        default:
            break;
    }
}

//	This callback function is called when a keyboard event occurs
bool jumped = false;
void myKeyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 27:
            exit(0);
            break;
        case 'a':
            gRoll += 3.0;
            break;
        case 'd':
            gRoll -= 3.0;
            break;
        case 'w':
            gPitch += 3.0;
            break;
        case 's':
            gPitch -= 3.0;
            break;
        default:
            break;
    }
}

//	This function is called after (at least) the specified time has ellapsed
//	since it was last "primed" (pushed back on the queue).
//
void myTimeOut(int dt)
{
    glutTimerFunc(20, myTimeOut, 0);
    glutPostRedisplay();
}


void myInit(void)
{
    GLfloat		ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat		diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat		position[] = {0.0, 3.0, 3.0, 0.0};

    GLfloat		lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat		local_view[] = {0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glFrontFace(GL_CW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //	 replaces the gluOrtho2D call.
    setupCamera();

	myDisplay();
}

void setupCamera(void)
{
	float FOVy, FOVxy;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	FOVy = 2 * atan(kChipHeight / (2*gFocalLength)) * RAD_TO_DEG;
	FOVxy = kChipWidth / (kSx * kChipHeight);
	
	// Here I could et the window's aspect ratio to be be equal to that
	//	of my camera's sensor.  Or just check & bail out.
	// Check & bail
    //	float winRatio = 1.f*winWidth/winHeight;
    //	// cannot differ by more than 5%
    //	assert(fabsf(winRatio-FOVxy)/FOVxy < 0.05f);
	//
	//	Enforce ratio
	winWidth = static_cast<int>(roundf(FOVxy*winHeight));

	gluPerspective(FOVy, FOVxy, gNearZ, gFarZ);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glShadeModel(GL_SMOOTH);
}

int main(int argc, char** argv)
{
	//	Initialize glut and create a new window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 40);
	glutCreateWindow("3D Graphic objects Demo");
	glViewport(0, 0, 400, 300);
	
	//	set up the callbacks
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(20, myTimeOut, 0);
	
	//	Now we can do application-level
	myInit();

	//	Now we enter the main loop of the program and to a large extend
	//	"loose control" over its execution.  The callback functions that 
	//	we set up earlier will be called when the corresponding event
	//	occurs
	glutMainLoop();
	
	//	This will never be executed (the exit point will be in one of the
	//	call back functions).
	return 0;
}
