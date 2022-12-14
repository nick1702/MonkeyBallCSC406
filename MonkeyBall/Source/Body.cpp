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

Body::Body(float x, float y, float z, float theta)
:
x_(x),
y_(y),
z_(z),
theta_(theta)
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

    gluCylinder(cyl_, cylRadius_, cylRadius_, torsoHeight_, 12, 8);
    
    rightArm_->draw();
    
    
    glPopMatrix();
    
    
}


