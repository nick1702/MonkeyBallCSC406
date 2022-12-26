#pragma once

#include "ApplConstants.h"
using namespace shapes2d;

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    Point3D a, b, c, d;
} Quad3D;

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

void draw_Quad3D(Quad3D quad) {

    setMaterial(0.7, 0.5, 0.3, 0., 0., 0., 0., 0., 0., 0.);

    glBegin(GL_POLYGON);
        glVertex3f(quad.a.x, quad.a.y, quad.a.z);
        glVertex3f(quad.b.x, quad.b.y, quad.b.z);
        glVertex3f(quad.c.x, quad.c.y, quad.c.z);
        glVertex3f(quad.d.x, quad.d.y, quad.d.z);
    glEnd();
}

