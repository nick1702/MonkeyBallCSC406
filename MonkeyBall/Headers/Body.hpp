//
//  Body.hpp
//  MonkeyBall
//
//  Created by Nicholas Powers on 11/29/22.
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>


class Body {
        //
        // Constructors and deconstructors
        //
    public:

    Body(float x, float y, float z, float theta);

    ~Body(void);

    //
    // public methods
    //

    void update(float t);
    
    

    /**    Disabled default constructor
     */
    Body(void) = delete;
    /**    Disabled copy constructor
     * @PARAM obj    object to copy
     */
    Body(const Body& obj) = delete;

    /**    Disabled move constructor
     * @PARAM obj    object to move
     */
    Body(Body&& obj) = delete;

    /**    Disabled copy operator
     * @PARAM obj    object to copy
     * @RETURN    reference to this object
     */
    const Body& operator = (const Body& obj) = delete;

    /**    Disabled move operator
     * @PARAM obj    object to move
     * @RETURN    reference to this object
     */
    Body& operator = (Body&& obj) = delete;

    private:

    //        private members
    float x_;
    float y_;
    float z_;
    float theta_;

    //        private methods
    
};

#endif /* Body_hpp */

