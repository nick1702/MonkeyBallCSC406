//
//  Limb.hpp
//  MonkeyBall
//
//  Created by Nicholas Powers on 11/29/22.
//

#ifndef Limb_hpp
#define Limb_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

#include "glPlatform.h"

class Limb {
        //
        // Constructors and deconstructors
        //
    public:

    Limb(std::vector<float> angles,float x, float y, float z, float limbLength, GLUquadric *cyl);

    ~Limb(void);

    //
    // public methods
    //
    

    void update(int vertexIndex, float theta);
    
    
    void draw(void);
    

    /**    Disabled default constructor
     */
    Limb(void) = delete;
    /**    Disabled copy constructor
     * @PARAM obj    object to copy
     */
    Limb(const Limb& obj) = delete;

    /**    Disabled move constructor
     * @PARAM obj    object to move
     */
    Limb(Limb&& obj) = delete;

    /**    Disabled copy operator
     * @PARAM obj    object to copy
     * @RETURN    reference to this object
     */
    const Limb& operator = (const Limb& obj) = delete;

    /**    Disabled move operator
     * @PARAM obj    object to move
     * @RETURN    reference to this object
     */
    Limb& operator = (Limb&& obj) = delete;

    private:

    //        private members
        std::vector<float> angles_;
        float x_;
        float y_;
        float z_;
        float limbLength_;
        GLUquadric *cyl_;
        
        

    //        private methods
    
};


#endif /* Limb_hpp */
