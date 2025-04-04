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
		"layout(location = 0) in vec3 aPos;\n"
		"uniform mat4 MVP;"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragmentShader =
		"#version 330 core\n"
		"out vec4 color;\n"
		"void main(void)\n"
		"{\n"
		"color = vec4(sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5,\n"
		"cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5,\n"
		"sin(gl_FragCoord.x * 0.15) * cos(gl_FragCoord.y * 0.15),\n"
		"1.0);"
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
