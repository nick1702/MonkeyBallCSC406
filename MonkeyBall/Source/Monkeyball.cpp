// Graphic Object 2D .cpp


#include <iostream>
#include <cfloat>
#include <stdlib.h>
#include "Monkeyball.hpp"

using namespace Monkey;
using namespace std;

typedef struct {
    Point3D a, b, m, d;
} Quad3D;

bool is_above_plane(Quad3D points);

Ball::Ball(float ox_, float oy_, float oz_)
:   ox(ox_),
    oy(oy_),
    oz(oz_),
    vx(0.f),
    vy(0.f),
    vz(0.f),
    ax(0.f),
    ay(0.f),
    az(0.f),
    x_angle(0.f),
    y_angle(0.f)
{
}

Ball::Ball(float ox_,
           float oy_,
           float oz_,
           float vx_,
           float vy_,
           float vz_,
           float x_angle_,
           float y_angle_,
           float scale_)
:   ox(ox_),
    oy(oy_),
    oz(oz_),
    vx(vx_),
    vy(vy_),
    vz(vz_),
    x_angle(x_angle_),
    y_angle(y_angle_)
    {
    }

Ball::~Ball(void) { }

Quad3D get_plane(float distance) {

    Point3D a = {0.0f, 0.0f, 0.0f}; 
    Point3D b = {0.0f, 0.0f, 0.0f}; 
    Point3D c = {0.0f, 0.0f, 0.0f}; 
    Point3D d = {0.0f, 0.0f, 0.0f}; 
    Quad3D amongus = {a, b, c, d};
    return amongus;
}

void Ball::update(float dt) {

    ox += vx*dt;
    oy += vy*dt;
    oz += vz*dt;

    // where do I get this function from
    // float angle_of_camera = get_camera_angle();
    // float ay = sinf(angle_of_camera);
    // or cosf

    vx += dt;
    vy += ay*dt;
    vz += 10*dt;

    // get_plane from remy
    Quad3D points = get_plane(0.0f);
    
    if (is_above_plane(points)) {
        // assuming a flat plane then any z should be the plane's z
        float plane_z = points.a.z;
        oz = plane_z + radius;
    }
}

// Questions
//
// Do I get the points relative to the ball (with the world 'flat') or relative to the camera (all over the place)
//
// How do I get the gravity i.e. get_camera_angle();
//
// How to draw sphere in openGL
//

void Ball::draw(void) const {

    glPushMatrix(); 
    
        glTranslatef(ox, oy, oz);

        float x_angle_deg = x_angle * 180 / 3.14159265;
        glRotatef(x_angle_deg, 1.f, 0.f, 0.f);

        float y_angle_deg = y_angle * 180 / 3.14159265;
        glRotatef(y_angle_deg, 0.f, 1.f, 0.f);

        

    glPopMatrix();

}

bool is_above_plane(Quad3D points) {

    float dxAB = points.b.x - points.a.x;
    float dyAB = points.b.y - points.a.y;
    float dzAB = points.b.z - points.a.z;
    float dxAD = points.d.x - points.a.x;
    float dyAD = points.d.y - points.a.y;
    float dzAD = points.d.z - points.a.z;
    float dxAM = points.m.x - points.a.x;
    float dyAM = points.m.y - points.a.y;
    float dzAM = points.m.z - points.a.z;

    float alpha = (dxAM * dyAD - dxAD * dyAM) / (-dxAD * dyAB + dxAB * dyAD);
    float beta = (dxAM * dyAB - dxAB * dyAM) / (dxAD * dyAB - dxAB * dyAD);

    // should be alpha^2, beta^2?
    if (abs(alpha) <= 1 && abs(beta) <= 1 && alpha + beta <= 1) {
        return true;
    } else {
        return false;
    }

}

