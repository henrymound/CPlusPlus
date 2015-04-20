/*
OpenGL is an API (Application Programming Interface) for rendering 2D and 3D graphics.

The names of OpenGL methods typically start with the letters gl. Below, for example, 
you'll see the following OpenGL method calls:

   glEnable(GL_DEPTH_TEST);
   glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
   glGenBuffers(1, &m_vertexBuffer);
   glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

and others. The calls are explained in more detail below.

In this project, we'll store information about a set of points and then ask OpenGL to 
render the points.

The points will be stored in an object called a Vertex Buffer Object (VBO). A VBO can 
hold information like positions or colors.

Here are the steps for using a VBO:

1. Generate a name for the buffer.
2. Bind (activate) the buffer.
3. Store data in the buffer.
4. Use the buffer to render the data.
5. Destroy the buffer.
*/

// For more on the why and how of header files and a brief explanation 
// of why multiple .cpp might be used in one project, see
// http://www.cplusplus.com/forum/articles/10627/
//
// #ifdef, #else and #endif are preprocessor directives like #include. See
// http://www.cplusplus.com/doc/tutorial/preprocessor/
// for more detail.
#ifdef _WIN32
#include <windows.h>
#else
#include <GL/glx.h>
#include "glx/glxext.h"
#endif

#include <iostream>
// STUDENTS: Add include file for srand() and rand()

// STUDENTS: Add include file for time() so you can use it to seed 
// a random number generator

#include <GL/gl.h>
#include <GL/glu.h>
#include "glext.h"
#include "example.h"

// Initialize procedure pointers glGenBuffers, glBinderBuffer, and glBufferData
// to NULL. This is wgl stuff that we don't need to worry about 
// at this point.
PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;

Example::Example()
{
}

bool Example::init()
{
	// Assign the appropriate procedure addresses to glGenbuffers, glBindBuffer, 
	// and glBufferData. More wgl stuff.
#ifdef _WIN32
    glGenBuffers = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
#else
    glGenBuffers = (PFNGLGENBUFFERSARBPROC)glXGetProcAddress((const GLubyte*)"glGenBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)glXGetProcAddress((const GLubyte*)"glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)glXGetProcAddress((const GLubyte*)"glBufferData");
#endif
    if (!glGenBuffers || !glBindBuffer || !glBufferData)
    {
        std::cerr << "VBOs are not supported by your graphics card" << std::endl;
        return false;
    }

	// STUDENTS: Seed a random number generator using srand() and time()

	// Enable z-buffer depth sorting (objects in front hide objects behind them)
    glEnable(GL_DEPTH_TEST);

	// Specify colors used to clear color buffers
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);

	// STUDENTS: Change this loop so that it creates 15 random vertices
	// Let
	// X range from -3.5f to 3.5f
	// Y stay at 0.0f
	// Z range from -2.5f to 2.5f
    for (float point = -4.0f; point < 5.0; point+=0.5f)
    {
        m_vertices.push_back(point); //X
        m_vertices.push_back(0.0f);  //Y
        m_vertices.push_back(0.0f);  //Z
    }

	// 1. Generate a name for the buffer.
	//		void glGenBuffers(GLsizei n, GLuint *buffers);
	//
	// In the method call below, we're generating one buffer name that will
	// be stored in m_vertexBuffer
    glGenBuffers(1, &m_vertexBuffer);

	// 2. Bind (activate) the buffer.
	//		void glBindBuffer(GLenum target, GLuint buffer);
	//
	// Besides GL_ARRAY_BUFFER, another possible target is GL_ELEMENT_ARRAY_BUFFER,
	// which may be used in more complex renderings.
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	// 3. Store data in the buffer.
	//		void glBufferData(GLenum target, GLsizeiptr size, 
	//			const GLvoid *data, GLenum usage);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_vertices.size(),
                 &m_vertices[0], GL_STATIC_DRAW);

    //Return success
    return true;
}

void Example::prepare(float dt)
{

}

void Example::render()
{
	// 4. Use the buffer to render the data.

	// Clear the color buffer and depth buffer with colors specified
	// above with glClearColor(): 0.5f, 0.5f, 0.5f, 0.5f
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Replace the current matrix with the identity matrix
    glLoadIdentity();

	// Position the camera with
	// gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	// first three args give position of camera
	// second three give point the camera's looking at
	// third three tell which way is up
    gluLookAt(0.0, 6.0, 0.1, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Enable a vertex array

	// Vertex arrays are a series of arrays that we declare
	// to OpenGL, which stores different per-vertex attributes ,
	// including positions and colors.

	// The GL_VERTEX_ARRAY parameter tells OpenGL that the array to be 
	// enabled is a collection of positions. Another common parameter is 
	// GL_COLOR_ARRAY, which tells OpenGL that the array to be enabled
	// is a collection of colors.
    glEnableClientState(GL_VERTEX_ARRAY);

	// Activate the buffer we loaded earlier
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	// Tells OpenGL that the array or part of the array contains vertices, and 
	// provides some details about the array so OpenGL knows how to use it
	//		void glVertexPointer(GLint size, GLenum type, 
	//			GLsizei stride, const GLvoid *array);
	//
	// The call below tells OpenGL that each vertex in the array has three 
	// elements (x, y, and z), and each element is a floating-point number.
	// The stride of 0 means there's no padding between vertices, and the 
	// final 0 says that the array starts at the first position in the array.
    glVertexPointer(3, GL_FLOAT, 0, 0);

    float pointSize = 0.5f;
    for (unsigned int i = 0; i < m_vertices.size() / 3; ++i)
    {
		// Change the size of a point in pixels with
		//		void glPointSize(GLfloat size)
        glPointSize(pointSize);

		// glDrawArrays() is the most common method for rendering arrays.
		//		void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		// where mode is a type of primitive to render. Different modes include
		// GL_POINTS, GL_LINES and GL_TRIANGLES
		// The call below asks OpenGL to draw one point at the location 
		// given by m_vertices[i*3]
        glDrawArrays(GL_POINTS, i, 1); 
        pointSize += 1.0f;
    }

	// Disable the client state when you're done with the array
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Example::shutdown()
{

}

void Example::onResize(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(52.0f, float(width) / float(height), 1.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
