#pragma once

class mesh {
	public:

		GLuint VBO, VAO;

		float vertices[9];
		mesh();
		~mesh();
		void draw();
		
};