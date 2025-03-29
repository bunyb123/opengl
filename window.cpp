
#include "window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

window::window(){
	
	if (!glfwInit()) {
		glfwTerminate();
	}

	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	gwindow = glfwCreateWindow(800,600, "triangle", NULL, NULL); 

	glfwMakeContextCurrent(gwindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetFramebufferSizeCallback(gwindow, framebuffer_size_callback);
	

	}
bool window::shouldClose() {
	return glfwWindowShouldClose(gwindow);
}
void window::swapBuffers() {
	glfwSwapBuffers(gwindow);
}

window::~window() {
	glfwTerminate();
}
void window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
};
void window::error_callback(int error, const char* description) {
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
};
