// Graphic Object 2D .cpp



#include "ApplConstants.h"
#include <iostream>
#include <cfloat>
#include "GraphicObject2D.hpp"

using namespace shapes2d;

bool GraphicObject2D::draw_bounding_boxes = false;

GraphicObject2D::GraphicObject2D(float ox_,
                                 float oy_)
:   ox(ox_),
    oy(oy_),
    vx(0.f),
    vy(0.f),
    angle(0.f),
    scale(1.f),
	min_x(FLT_MAX),
	max_x(FLT_MIN),
	min_y(FLT_MAX),
	max_y(FLT_MIN)
{
}

GraphicObject2D::GraphicObject2D(const Point2D& pt_)
:	GraphicObject2D(pt_.x, pt_.y)
	{
	}

GraphicObject2D::GraphicObject2D(float ox_,
                                 float oy_,
                                 float vx_,
                                 float vy_,
                                 float angle_,
                                 float scale_)
:   ox(ox_),
    oy(oy_),
    vx(vx_),
    vy(vy_),
    angle(angle_),
    scale(scale_),
	min_x(FLT_MAX),
	max_x(FLT_MIN),
	min_y(FLT_MAX),
	max_y(FLT_MIN)
    {
    }

GraphicObject2D::GraphicObject2D(const Point2D& pt_,
								 float vx_,
								 float vy_,
								 float angle_,
								 float scale_)
:	GraphicObject2D(pt_.x, pt_.y, vx_, vy_, angle_, scale_)
	{
	}

GraphicObject2D::~GraphicObject2D(void) { }

void GraphicObject2D::update(float dt) {
    ox += vx*dt;
    oy += vy*dt;

    if (ox > World2D::X_MAX) {
        ox -= World2D::WORLD_WIDTH;
    }
    if (ox < World2D::X_MIN) {
        ox += World2D::WORLD_WIDTH;
    }
    if (oy < World2D::Y_MAX) {
        oy -= World2D::WORLD_HEIGHT;
    }
    if (oy > World2D::Y_MIN) {
        oy += World2D::WORLD_HEIGHT;
    }

	update_bounding_box();
}

bool GraphicObject2D::collides_with(GraphicObject2D *object) {

    bool does_collide = false;
    

    // Check if 4 corners of object 1's bounding box are inside of object 2's bounding box

    if (object->isInside(this->min_x, this->min_y) || 
        object->isInside(this->max_x, this->min_y) ||
        object->isInside(this->min_x, this->max_y) ||
        object->isInside(this->max_x, this->max_y))
    {
        does_collide = true;
    }

    // Check if 4 corners of object 2's bounding box are inside of object 1's bounding box

    if (this->isInside(object->min_x, object->min_y) || 
        this->isInside(object->max_x, object->min_y) ||
        this->isInside(object->min_x, object->max_y) ||
        this->isInside(object->max_x, object->max_y))
    {
        does_collide = true;
    }

    return does_collide;
}


void GraphicObject2D::get_bounding_box(float& min_x,
									   float& max_x,
									   float& min_y,
									   float& max_y) const
{
	min_x = this->min_x;
	max_x = this->max_x;
	min_y = this->min_y;
	max_y = this->max_y;
}

void GraphicObject2D::toggle_show_bounding_boxes(void)
{
	draw_bounding_boxes = !draw_bounding_boxes;
}

void GraphicObject2D::draw_bounding_box(void) const
{
	glPushMatrix();

        glColor3f(1.f, 0.f, 0.f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(min_x, min_y);
            glVertex2f(max_x, min_y);
            glVertex2f(max_x, max_y);
            glVertex2f(min_x, max_y);
        glEnd();

	glPopMatrix();
}

bool GraphicObject2D::isInside(float x_, float y_) const
{
	return (x_ >= min_x) &&
           (x_ <= max_x) &&
           (y_ >= min_y) &&
           (y_ <= max_y);
}

