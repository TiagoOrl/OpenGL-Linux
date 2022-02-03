#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "shader.hpp"
#include "VBO.hpp"
#include "VAO.hpp"
#include "EBO.hpp"

// install:
// libgl1-mesa-dev
// libglu1-mesa-dev
// libglfw3-dev
// libglfw3

// download build and include glad.h and glad.c


const char * vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos; \n"

"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
"}\0";

const char * fragmentShaderSource = 
"#version 330 core \n"
"out vec4 FragColor; \n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.2f, 0.7f, 0.02f, 1.0f); \n"
"}\0";


int main() {
    glfwInit();

    // tell GLFW what version of OpenGL we are using it = 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Tell GLFW we are using the CORE profile, means we only have Modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = 
    {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
         0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
         0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
        -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
         0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
         0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
    };

    GLuint indexes[] = 
    {
        0,3,5, // lower left triangle
        3,2,4, // lower right triangle
        5,4,1  // upper triangle
    };


    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // add created window to current context
    glfwMakeContextCurrent(window);

    // load GLAD so it configures OpenGL
    gladLoadGL();

    // specify render viewport
    glViewport(0, 0, 600, 600);

    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indexes, sizeof(indexes));
    

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // background color
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // clear the back buffer and assing the new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // swap back buffer with the front buffer to render the color
    glfwSwapBuffers(window);


    while (!glfwWindowShouldClose(window)) 
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window); 

        // handle GLFW events
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
}