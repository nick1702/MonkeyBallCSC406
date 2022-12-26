// Graphic Object 2D .cpp
#pragma once

#include <iostream>
#include <cfloat>
#include <stdlib.h>
#include "Monkeyball.hpp"

using namespace Monkey;
using namespace std;

extern Quad3D plane;
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
    y_angle(0.f),
    radius(0.2f)
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
           float radius,
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

    // where do I get this function from
    // float angle_of_camera = get_camera_angle();
    // float ay = sinf(angle_of_camera);
    // or cosf

    // vx += dt;
    // vy += ay*dt;
    // vz += 1*dt;uu
    // get_plane from remy
    
    float transMatrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, transMatrix);

    ax = transMatrix[1];
    ay = transMatrix[5];

    vx += -0.001*ax*dt;
    vy += -0.001*ay*dt;

    ox += vx*dt;
    oy += vy*dt;

    Point3D prev_xyz = get_xyz();
    Point3D next_xyz = get_xyz();
    next_xyz.z = (oz + -(0.005*10) + vz*dt - radius);
    optional<float> after_move = is_above_plane(plane, next_xyz);


    if (after_move.has_value()           && // ball in same axis as plane (must be first expression)
        after_move.value() < 0           && // move puts ball below plane
        prev_xyz.z >= plane.a.z + radius && // ball is currently above plane (not below)
        vz <= 0)                            // ball isn't moving up
    {
        prev_xyz.z = plane.a.z + radius;
        set_xyz(prev_xyz);
    }
    else {
        next_xyz.z += radius;
        set_xyz(next_xyz);
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
    
        glColor4f(COLOR[kGREEN][0],
                  COLOR[kGREEN][1],
                  COLOR[kGREEN][2],
                  COLOR[kGREEN][3]);

        glTranslatef(ox, oy, oz);

        // float x_angle_deg = x_angle * 180 / 3.14159265;
        // glRotatef(x_angle_deg, 1.f, 0.f, 0.f);

        // float y_angle_deg = y_angle * 180 / 3.14159265;
        // glRotatef(y_angle_deg, 0.f, 1.f, 0.f);

        glutSolidSphere(radius, 20, 20);

    glPopMatrix();

}

optional<float> Ball::is_above_triangle(Point3D a, Point3D b, Point3D c, Point3D p) {

    float s1 = c.y - a.y;
    float s2 = c.x - a.x;
    float s3 = b.y - a.y;
    float s4 = p.y - a.y;

    float alpha = (a.x * s1 + s4 * s2 - p.x * s1) / (s3 * s2 - (b.x-a.x) * s1);
    float beta = (s4 - alpha * s3) / s1;

    if (alpha >= 0 && beta >= 0 && (alpha + beta) <= 1)
        return (p.z - a.z) - ((alpha * (b.z - a.z)) + (beta * (c.z - a.z)));
    else 
        return {};

    // float dxAB = b.x - a.x;
    // float dyAB = b.y - a.y;
    // float dzAB = b.z - a.z;
    // float dxAC = c.x - a.x;
    // float dyAC = c.y - a.y;
    // float dzAC = c.z - a.z;
    // float dxAM = ox - a.x;
    // float dyAM = oy - a.y;
    // float dzAM = (oz - radius) - a.z;

    // float alpha = ((dxAM * dyAC) - (dxAC * dyAM)) / ((-dxAC * dyAB) + (dxAB * dyAC));
    // float beta = ((dxAM * dyAB) - (dxAB * dyAM)) / ((dxAC * dyAB) - (dxAB * dyAC));

    // return (alpha >= 0 && beta >= 0 && (alpha+beta) <= 1);
    // return (dzAM - radius) + (alpha * dzAB + beta * dzAC);
}

int count = 0;
optional<float> Ball::is_above_plane(Quad3D quad, Point3D point) {

    optional<float> t1 = is_above_triangle(quad.a, quad.b, quad.d, point);
    optional<float> t2 = is_above_triangle(quad.b, quad.c, quad.d, point);

    if (t1.has_value()) return t1.value();
    if (t2.has_value()) return t2.value();

    return {};
 
}


