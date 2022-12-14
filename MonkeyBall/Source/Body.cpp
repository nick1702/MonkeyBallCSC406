//
//  Body.cpp
//  MonkeyBall
//
//  Created by Nicholas Powers on 11/29/22.
//

#include "Body.hpp"

GLUquadric* Body::cyl_ = gluNewQuadric();

float Body::cylRadius_ = 0.1f;
float Body::torsoHeight_ = 0.5f;

Body::Body(float x, float y, float z)
:
x_(x),
y_(y),
z_(z)
{
    init();
}



void Body::init(void)
{
//    right arm
    std::vector<float> rightArmAngles;
    rightArmAngles.push_back(70.f);
    rightArmAngles.push_back(20.f);
    rightArm_ = new Limb(rightArmAngles,cylRadius_, 0.f, torsoHeight_,0.25f, cyl_);
    
}

void Body::draw(void)
{
    glPushMatrix();
    glTranslatef(x_, y_, z_);
    
//    draw torso
    setMaterial(1.0, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
    gluCylinder(cyl_, cylRadius_, cylRadius_, torsoHeight_, 12, 8);
    
    setMaterial(0.0, 1.0, 0., 0., 0., 0., 0., 0., 0., 0.);
    rightArm_->draw();
    
    
    glPopMatrix();
    
    
}


void Body::setMaterial(GLfloat ambRed, GLfloat ambGreen, GLfloat ambBlue, GLfloat difRed,
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


