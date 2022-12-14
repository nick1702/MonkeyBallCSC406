//
//  Limb.cpp
//  MonkeyBall
//
//  Created by Nicholas Powers on 11/29/22.
//


#include "Limb.hpp"

Limb::Limb(std::vector<float> angles,float x, float y, float z,float limbLength, GLUquadric *cyl)
:
    angles_(angles),
    x_(x),
    y_(y),
    z_(z),
    limbLength_(limbLength),
    cyl_(cyl)
{
}

void Limb::update(int vertexIndex, float theta)
{
    angles_[vertexIndex] = theta;
}

void Limb::draw()
{
    glPushMatrix();
    glTranslatef(x_, y_, z_);
    for(int i = 0; i < angles_.size();i++)
    {
        glRotatef(angles_[i], 1.f, 0.f, 0.f);
        gluCylinder(cyl_, 0.1, 0.1, limbLength_, 12, 8);
        glTranslatef(0.f, 0.f, limbLength_);
    }
    glPopMatrix();
}
