#pragma once
#include <glad/glad.h>

class shaders {
public:
	GLuint shaderProgram;
	const char* vertexShader;
	const char* fragmentShader;
	shaders();
	GLuint createShader(unsigned int shaderType, const char* shaderSource);
	GLuint createProgram();


};