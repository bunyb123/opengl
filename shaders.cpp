#include <glad/glad.h>
#include "shaders.h"
#include <iostream>



GLuint shaderProgram;

shaders::shaders(){
	shaderProgram = createProgram();
	glUseProgram(shaderProgram);
}

GLuint shaders::createShader(unsigned int shaderType, const char* shaderSource)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return shader;
}
GLuint shaders::createProgram() {
	const char* vertexShader =
		"#version 330 core\n"
		"#extension GL_ARB_separate_shader_objects : enable\n"
		"layout(location = 0) in vec3 aPos;\n"
		"layout(location = 1) in vec3 vertexColor;\n"
		"out vec3 fragmentColor;\n"
		"uniform mat4 MVP;"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"fragmentColor = vertexColor;"
		"}\0";

	const char* fragmentShader =
		"#version 330 core\n"
		"in vec3 fragmentColor;"
		"out vec3 color;\n"
		"void main(void)\n"
		"{\n"
		"color = fragmentColor;\n"
		"}\0";
	shaderProgram = glCreateProgram();

	GLuint vs = createShader(GL_VERTEX_SHADER, vertexShader);

	GLuint fs = createShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);

	glLinkProgram(shaderProgram);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return shaderProgram;
}

GLuint shaders::getShader()
{
	return shaderProgram;
}
