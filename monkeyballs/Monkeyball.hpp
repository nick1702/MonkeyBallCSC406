//  Ball.h

#pragma once

#include <optional>
#include "glPlatform.h"
#include "utils.hpp"

namespace Monkey {

    class Ball {

    public:

        void update(float dt);
        void draw(void) const;

        float get_vx(void) const {return vx;}
        void set_vx(float vx_) {vx = vx_;}

        float get_vy(void) const {return vy;}
        void set_vy(float vy_) {vy = vy_;}

        float get_vz(void) const {return vz;}
        void set_vz(float vz_) {vz = vz_;}

        float get_ox(void) const { return ox; }
        void set_ox(float ox_) { ox = ox_; }
        
        float get_oy(void) const { return oy; }
        void set_oy(float oy_) { oy = oy_; }
        
        float get_oz(void) const { return oz; }
        void set_oz(float oz_) { oz = oz_; }
        
        float get_x_angle() { return x_angle; }
        void set_x_angle(float x_angle_) { x_angle = x_angle_; }
        
        float get_y_angle() { return y_angle; }
        void set_y_angle(float y_angle_) { y_angle = y_angle_; }
        
        float get_radius(void) const { return radius; }
        void set_radius(float radius_) { radius = radius_; }

        Point3D get_xyz(void) const {
            Point3D xyz = {ox, oy, oz};
            return xyz;
        }

        void set_xyz(Point3D point) {
            ox = point.x;
            oy = point.y;
            oz = point.z;
        }

        ~Ball(void);
 
        bool collides_with(Ball *object);

        std::optional<float> is_above_plane(Quad3D quad, Point3D point);
        std::optional<float> is_above_triangle(Point3D a, Point3D b, Point3D c, Point3D p);

        Ball(float ox, float oy, float oz); 
        Ball(float ox, float oy, float oz, float vx, float vy, float vz, float x_angle, float y_angle, float radius, float scale);

    private:

        float ox,
              oy,
              oz;

        float vx,
              vy,
              vz;

        float ax,
              ay,
              az;

        float x_angle;
        float y_angle;

        float radius;
        float above_plane = false;
        
    };

}

