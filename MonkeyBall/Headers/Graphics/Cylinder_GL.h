/*==================================================================================+#																					##	File:		Cylinder_GL.h														##																					##	Headers for the OpenGL version of the Cylinder class.							##																					##																					##-----------------------------------------------------------------------------------##	Author:			jean-yves herve', Dept of CS, U. of Rhode Island and			##					GRPR, Ecole Polytechnique de Montreal							##																					##	Date Creation:	May 2001														##																					##	Modifications:																	##																					#+==================================================================================*/#ifndef	CYLINDER_GL_H#define	CYLINDER_GL_H#include "glPlatform.h"//#include "glUtils.h"#include "GraphicObject_GL.h"//----------------------------------------------------------------------------------//-----------------------------------Class definition-------------------------------//class Cylinder_GL : public GraphicObject_GL{	public:		//		//	Constructor and destructor			//		Cylinder_GL(GLfloat *origin, GLfloat **axes, bool isClosed);		Cylinder_GL(GLfloat *origin, GLfloat *dirAxis, GLfloat radius,	bool isClosed);		virtual ~Cylinder_GL(void);		//		//	Public methods		//		void setResolution(ResolutionLevel res);		void setResolution(ResolutionLevel circRes, ResolutionLevel slabRes);		void draw(void);					private:		//		//	private members ---> All indices are 0-based <---		//		GLfloat	***vertex,				**normal,				normalTop[3],				normalBottom[3];		short	slabStep,				circStep;		bool	closedCyl;		//		static bool initCtSt;		static GLfloat ct[kVeryHighDefCircPts], st[kVeryHighDefCircPts];		//		//		void init(GLfloat *origin, GLfloat **axes);		//		static bool initStatic(void);};#endif