#version 330 core 
out vec4 FragColor; 

// inputs/imports data from vertex shader
in vec3 color;
in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
   // add color to the primitive
   // FragColor = vec4(color, 1.0f);
   FragColor = texture(tex0, texCoord);
}