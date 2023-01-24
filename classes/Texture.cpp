#include "Texture.hpp"


Texture::Texture(const char* imagePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
    type = texType;
    // load up texture from img file
    int imgWidth, imgHeight, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* imgData = stbi_load(imagePath, &imgWidth, &imgHeight, &channels, 0);

    // Generates an OpenGL texture object
	glGenTextures(1, &ID);
	// Assigns the texture to a Texture Unit
	glActiveTexture(slot);
	glBindTexture(texType, ID);

    // Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Configures the way the texture repeats (if it does at all)
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Assigns the image to the OpenGL Texture object
	glTexImage2D(texType, 0, GL_RGB, imgWidth, imgHeight, 0, format, pixelType, imgData);
	// Generates MipMaps
	glGenerateMipmap(texType);

    // Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(imgData);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}


void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
	glUniform1i(texUni, unit);
}

void Texture::Bind() {
    glBindTexture(type, ID);
}

void Texture::Unbind() {
    glBindTexture(type, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &ID);
}
