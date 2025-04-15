
#include "window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>



void GLAPIENTRY MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? " GL ERROR " : ""),
		type, severity, message);
}

window::window(){
	
	if (!glfwInit()) {
		glfwTerminate();
	}

	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);



	gwindow = glfwCreateWindow(800,600, "triangle", NULL, NULL); 

	glfwMakeContextCurrent(gwindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetFramebufferSizeCallback(gwindow, framebuffer_size_callback);
	glDebugMessageCallback(MessageCallback, 0);
	

	}
bool window::shouldClose() {
	return glfwWindowShouldClose(gwindow);
}
float window::getTime()
{
	return glfwGetTime();
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



