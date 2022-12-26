#ifndef APPL_CONTANTS__H
#define APPL_CONTANTS__H

#include <string>

namespace shapes2d {

    //  note how the enum element kNB_COLORS *automatically* ends up storing the number of
    //  colors that I defined.
    enum ColorIndex
    {
        kWHITE = 0,
        kRED,
        kGREEN,
        kBLUE,
        kYELLOW,
        kORANGE,
        kPURPLE,
        kBROWN,
        kPINK,
        kGREY,
        kNOCOLOR,
        //
        kNB_COLORS
    };


    static	float	COLOR[kNB_COLORS][4] = {	{1.f, 1.f, 1.f, 1.f},	//	white
                                                {1.f, 0.f, 0.f, 1.f},	//	red
                                                {0.f, 1.f, 0.f, 1.f},	//	green
                                                {0.f, 0.f, 1.f, 1.f},	//	blue
                                                {1.f, 1.f, 0.f, 1.f},	//	yellow
                                                {1.f, 0.6f, 0.2f, 1.f},  // orange
                                                {0.4f, 0.f, 0.7f, 1.f},  // purple
                                                {0.2f, 0.1f, 0.f, 1.f},  // brown
                                                {1.f, 0.f, 0.5f, 1.f},   // pink
                                                {0.5f, 0.5f,0.5f, 1.f}, //  grey
                                                {0.f, 0.f, 0.f, 0.f},    // no color
                                            };

    static const std::string colorMenuStr[kNB_COLORS] =	{	"White",
                                                            "Red",
                                                            "Green",
                                                            "Blue",
                                                            "Yellow",
                                                            "Orange",
                                                            "Purple",
                                                            "Brown",
                                                            "Pink",
                                                            "Grey",
                                                            "No Color",
                                                        };

    static int  colorMenuCode[kNB_COLORS] = {   kWHITE,
                                                kRED,
                                                kGREEN,
                                                kBLUE,
                                                kYELLOW,
                                                kORANGE,
                                                kPURPLE,
                                                kBROWN,
                                                kPINK,
                                                kGREY,
                                                kNOCOLOR,
                                            };


    enum SizeIndex
    {
        kTINY = 0,
        kVERY_SMALL,
        kSMALL,
        kMEDIUM,
        kLARGE,
        kVERY_LARGE,
        kHUGE,
        //
        kNB_SIZES
    };

    static	float	SCALE[kNB_SIZES] = {0.05f,  //  kTINY
                                        0.10f,  //  kVERY_SMALL
                                        0.15f,  //  kSMALL
                                        0.20f,  //  kMEDIUM
                                        0.25f,  //  kLARGE
                                        0.30f,  //  kVERY_LARGE
                                        0.35f}; //  kHUGE

    static const std::string segSizeMenuStr[kNB_SIZES] =	{	"Tiny",
                                                                "Very small",
                                                                "Small",
                                                                "Medium",
                                                                "Large",
                                                                "Very large",
                                                                "Huge"
                                                            };


    const float   ANGLE_INCREMENT = 10.f;


	enum WorldType {
		BOX_WORLD,
		CYLINDER_WORLD,
		TORUS_WORLD
	
	};
	
	
    class World2D {
        
        public:
            /**    Disabled default constructor
             */
            World2D(void) = delete;
            /**    Disabled copy constructor
             * @PARAM obj    object to copy
             */
            World2D(const World2D& obj) = delete;
        
            /**    Disabled move constructor
             * @PARAM obj    object to move
             */
            World2D(World2D&& obj) = delete;
        
            /**    Disabled copy operator
             * @PARAM obj    object to copy
             * @RETURN    reference to this object
             */
            const World2D& operator = (const World2D& obj) = delete;
        
            /**    Disabled move operator
             * @PARAM obj    object to move
             * @RETURN    reference to this object
             */
            World2D& operator = (World2D&& obj) = delete;

			static const float X_MIN, X_MAX, Y_MIN, Y_MAX, WORLD_WIDTH, WORLD_HEIGHT;
			
			static WorldType worldType;
        
    };
    
}


#endif  //  APPL_CONTANTS__H
