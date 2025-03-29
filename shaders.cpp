#include <glad/glad.h>
#include "shaders.h"
#include <iostream>




const char* vertexShader =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShader =
"#version 330 core\n"
"out vec4 color;\n"
"void main() {\n"
"color = vec4(0.0f, 0.5f, 1.0f, 1.0f);\n"
"}\0";
shaders::shaders(){

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