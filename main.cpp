#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <windows.h>
#include "mesh.h"
#include "shaders.h"
#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


int main() {
	window gwindow;
	mesh Triangle;
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		mesh triangle2;


		double lastTime = gwindow.getTime();
		double fps = 1.0 / 60;

		while (!gwindow.shouldClose()) {
			double deltaTime = glfwGetTime() - lastTime;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();

			Triangle.draw();

			gwindow.swapBuffers();
			if (1.0 - fps > deltaTime) {
				Sleep(1.0 / fps - deltaTime);
			}
			lastTime = glfwGetTime();
		}

	return 0;

}

