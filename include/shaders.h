#pragma once
#include <glad/glad.h>
#include "shaders.h"

class shaders {
public:
	GLuint shaderProgram;
	const char* vertexShader;
	const char* fragmentShader;
	shaders();
	GLuint createShader(unsigned int shaderType, const char* shaderSource);
	GLuint createProgram();
	GLuint getShader();


};