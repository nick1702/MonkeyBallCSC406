/*==================================================================================+#																					##	File:		tubularSection_GL.h													##																					##	Headers for the OpenGL version of the TubularSection class.						##																					##																					##-----------------------------------------------------------------------------------##	Author:			jean-yves herve', Dept of CS, U. of Rhode Island and			##					GRPR, Ecole Polytechnique de Montreal							##																					##	Date Creation:	June 2001														##																					##	Modifications:																	##																					#+==================================================================================*/#ifndef	TUBULAR_SECTION_GL_H#define	TUBULAR_SECTION_GL_H#include "glUtils.h"#include "GraphicObject_GL.h"//----------------------------------------------------------------------------------//-----------------------------------Class definition-------------------------------//class TubularSection_GL : public GraphicObject_GL{	public:		//		//	Constructor and destructor			//		TubularSection_GL(GLfloat *origin, GLfloat **axes, GLfloat theta0, GLfloat thetaf);		TubularSection_GL(GLfloat *origin, GLfloat *dirAxis, GLfloat radius, GLfloat theta0,							GLfloat thetaf);		~TubularSection_GL(void);		//		//	Public methods		//		void setResolution(ResolutionLevel res);		void setResolution(ResolutionLevel circRes, ResolutionLevel slabRes);		void draw(void);			protected:		//		GLfloat	***vertex,				**normal;		short	nbCircSegs,				circStep,				slabStep;				private:		//		//	private members ---> All indices are 0-based <---		//		GLfloat	startAngle, stopAngle;		short	tubeType;		//		//		void init(GLfloat *origin, GLfloat **axes, GLfloat theta0, GLfloat dTheta);};#endif