#include <glad/glad.h>
#include "shaders.h"
#include <iostream>




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
		"#version 450 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"layout(location = 1) in vec2 aTexCoord;\n"
		"out vec2 vTexCoord;\n"
		"uniform mat4 MVP;\n"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(aPos, 1);\n"
		"vTexCoord = aTexCoord;\n"
		"}\0";

	const char* fragmentShader =
		"#version 450 core\n"
		"in vec2 vTexCoord;\n"
		"out vec4 fragColor;\n"
		"uniform sampler2D myTextureSampler;\n"
		"void main(void)\n"
		"{\n"
		"fragColor = texture(myTextureSampler, vTexCoord);\n"
		"}\0";
	shaderProgram = glCreateProgram();

	GLuint vs = createShader(GL_VERTEX_SHADER, vertexShader);

	GLuint fs = createShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);

	glLinkProgram(shaderProgram);
	GLint linkStatus;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
	if (linkStatus == GL_FALSE) {
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cerr << "Shader LINK ERROR: " << infoLog << std::endl;
		return 0;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);

	return shaderProgram;
}

GLuint shaders::getShader()
{
	return shaderProgram;
}
