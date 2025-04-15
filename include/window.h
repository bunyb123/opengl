#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class window {
	public:
		GLFWwindow* gwindow;
		window();
		~window();
		void swapBuffers();
		bool shouldClose();
		float getTime();
		static void error_callback(int error, const char* description);
		static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
};