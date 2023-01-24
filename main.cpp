#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "classes/shader.hpp"
#include "classes/VBO.hpp"
#include "classes/VAO.hpp"
#include "classes/EBO.hpp"
#include "classes/Texture.hpp"
#include "stb/stb_image.h"

// install:
// libgl1-mesa-dev
// libglu1-mesa-dev
// libglfw3-dev
// libglfw3

// download build and include glad.h and glad.c


int main() {
    glfwInit();

    // tell GLFW what version of OpenGL we are using it = 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Tell GLFW we are using the CORE profile, means we only have Modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = 
    //    COORDINATES       /    COLOURS          / TEXTURE COORDS
    {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 1.0f,  1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f   
    };

    GLuint indexes[] = 
    {
        0, 2, 1, //upper triangle
        0, 3, 2  // lower triangle
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

    // creates the shaders vertex and fragment
    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

    // vertex array object init and binding
    VAO VAO1;
    VAO1.Bind();

    // vertex buffer and elements buffer objects
    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indexes, sizeof(indexes));
    

    // link the VBO attributes such as coordinates, colors and textures
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*) 0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*) (3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*) (6 * sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    Texture brickWall("textures/brick_wall.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    brickWall.texUnit(shaderProgram, "tex0", 0);

    while (!glfwWindowShouldClose(window)) 
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        glUniform1f(uniID, 0.5f);
        // Binds texture so that is appears in rendering
		brickWall.Bind();
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window); 

        // handle GLFW events
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    brickWall.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
}