#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "mesh.h"
#include "shaders.h"
#include "string"
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>



mesh::mesh() {
    shaders myshaders;
    float vertices[12] = {
    1.0f,  0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 1.0f,
   -0.5f, -0.5f, 0.0f, 1.0f
    };

    GLuint MatrixID = glGetUniformLocation(myshaders.getShader(), "MVP");
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
}

void mesh::draw() {
    glUseProgram(myshaders.getShader());


    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, 3), 
        glm::vec3(0, 0, 0), 
        glm::vec3(0, 1, 0) 
    );

    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 mvp = Projection * View * Model;

    GLuint MatrixID = glGetUniformLocation(myshaders.getShader(), "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);


    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

mesh::~mesh() {
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}