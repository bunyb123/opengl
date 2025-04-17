#pragma once
#include "shaders.h"
#include <iostream>

class mesh {
	public:

		GLuint VBO, VAO;
		GLuint tvao;
		GLuint triangleBuffer;
		GLuint texturebuffer;
		GLuint MatrixID;
		shaders myshaders;
		GLfloat vertices[12 * 3];
		GLfloat colors[12 * 3 * 3];
		GLuint texture;
		mesh();
		~mesh();
		void draw();
		GLuint load_BMP(const char* imagepath);
};