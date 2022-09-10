#pragma once
#include "Shader.h"
#include <iostream>
#include <vector>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
class Triangle
{
public:
    GLuint VBO, VAO,EBO;
    GLfloat vertices[9]= {
         -0.5f,  0.0f, 0.0f,
          0.5f,  0.0f, 0.0f,
          0.0f, 0.5f, 0.0f,};
    GLuint indices[3] = {0, 1, 2};
    void setup();
    void start_position(std::vector<float> pos);
    void translate(float x, float y);
    void draw();
    Triangle(std::vector<float> pos)
    {
        start_position(pos);
        setup();
        Shader ourShader("A:/OpenGLtasks/Figures/Project1/Project1/Shaders/shader.vs", "A:/OpenGLtasks/Figures/Project1/Project1/Shaders/shader.fs");
        ourShader.Use();
    }
};
void Triangle::start_position(std::vector<float> pos)
{
    vertices[0] += pos[0];
    vertices[1] += pos[1];
    vertices[3] += pos[0];
    vertices[4] += pos[1];
    vertices[6] += pos[0];
    vertices[7] += pos[1];

}
void Triangle::setup()
{
   
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


}

void Triangle::translate(float x, float y)
{
    vertices[0] += x;
    vertices[3] += x;
    vertices[6] += x;
    vertices[1] += y;
    vertices[4] += y;
    vertices[7] += y;
    this->setup();
}

void Triangle::draw()
{
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
