#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "mesh.h"
#include "shaders.h"
#include <iostream>



int main() {
	window gwindow;
	mesh Triangle;
	shaders myshaders;

	glUseProgram(myshaders.getShader());

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		while (!gwindow.shouldClose()) {

			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			Triangle.draw();
			gwindow.swapBuffers();
		}

	return 0;

}

