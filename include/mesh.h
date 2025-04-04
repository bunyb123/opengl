#pragma once
#include "shaders.h"

class mesh {
	public:

		GLuint VBO, VAO;
		GLuint MatrixID;
		shaders myshaders;
		float vertices[12];
		mesh();
		~mesh();
		void draw();
		
};