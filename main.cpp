#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "mesh.h"
#include "shaders.h"
#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


int main() {
	window gwindow;
	mesh Triangle;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		while (!gwindow.shouldClose()) {

			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();

			Triangle.draw();

			gwindow.swapBuffers();
		}

	return 0;

}

