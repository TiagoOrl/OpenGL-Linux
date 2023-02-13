#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H


#include <glad/glad.h>
#include <stb/stb_image.h>
#include "shader.hpp"

class Texture {
    public:
        GLuint ID;
        GLenum type;
        GLuint unit;

        Texture(const char* imagePath, GLenum texType, GLuint slot, GLenum format, GLenum pixelType);
        void texUnit(Shader& shader, const char* uniform, GLuint unit);
        // bind a texture
        void Bind();
        void Unbind();
        void Delete();
};

#endif