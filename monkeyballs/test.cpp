#include "glPlatform.h"
#include "Monkeyball.cpp"
#include "utils.hpp"

Ball *ball = new Ball(0.f, 0.f, 0.f);

Point3D p1 = { -1.5, -1.5, -0.5 };
Point3D p2 = { +1.5, -1.5, -0.5 };
Point3D p3 = { +1.5, +1.5, -0.5 };
Point3D p4 = { -1.5, +1.5, -0.5 };
Quad3D plane = { p1, p2, p3, p4 };

void update_test(void) {

    ball->update(0.5);
    ball->draw();

    draw_Quad3D(plane);

}
