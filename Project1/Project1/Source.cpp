#pragma once
#include <iostream>
#include <tuple>
#include "windows.h"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other includes
#include "Shader.h"
#include "Triangle.cpp"
#include "Square.cpp"


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Figures", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    std::vector<float> pos = { 0.0f,0.0f };
    std::vector<float> pos1 = { 0.0f,0.0f };
    std::vector<float> color = { 0.0f, 0.5f, 1.0f };
    Triangle obj(pos);
    Square obj1(pos1);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        obj.draw();
        obj1.draw();
        glfwSwapBuffers(window);
    }
    glDeleteVertexArrays(1, &obj.VAO);
    glDeleteBuffers(1, &obj.VBO);
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << xpos << " " << ypos<<std::endl;
}