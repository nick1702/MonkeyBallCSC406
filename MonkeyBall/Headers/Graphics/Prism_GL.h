/*==================================================================================+#																					##	File:		prism_GL.h															##																					##	Headers for the OpenGL version of the Prism class.								##																					##	Prism can be closed or open, and smooth or not smooth.  A smooth prism has 		##	normal vectors attached to the vertices of the mesh, whereas a non-smooth		##	prism has average normals attached to the faces of the mesh.					##																					##-----------------------------------------------------------------------------------##	Author:			jean-yves herve', Dept of CS, U. of Rhode Island and			##					GRPR, Ecole Polytechnique de Montreal							##																					##	Date Creation:	May 2001														##																					##	Modifications:																	##																					#+==================================================================================*/#ifndef	PRISM_GL_H#define	PRISM_GL_H#include "glUtils.h"#include "GraphicObject_GL.h"//----------------------------------------------------------------------------------//-----------------------------------Class definition-------------------------------//class Prism_GL : public GraphicObject_GL{	public:		//		//	Constructor and destructor			//		Prism_GL(short n, GLfloat **topFace, GLfloat **bottomFace, bool isClosed,					bool isSmooth);		Prism_GL(short n, GLfloat **bottomFace, GLfloat *axis,					bool isClosed, bool isSmooth);		virtual ~Prism_GL(void);		//		//	Public methods		//		void setResolution(ResolutionLevel res);		void draw(void);					private:		//		//	private members ---> All indices are 0-based <---		//		ResolutionLevel	resolution;		GLfloat	***vertex,				**normalF,		//	face normal (for non-smooth prism)				***normalV,		//	vertex normal (for smooth prism)				*normalTop,				*normalBottom;		short	slabStep,				nbPtsPerSlice;		bool	closedPrism,				smoothPrism;		//		//				void init(GLfloat **topFace, GLfloat **bottomFace);		void init(GLfloat **bottomFace, GLfloat *axis);		};#endif