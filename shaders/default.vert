#version 330 core
layout (location = 0) in vec3 aPos; 
layout (location = 1) in vec3 aColor; 
layout (location = 2) in vec2 aTex;

// outputs the colors and texture coords to the fragment shader
out vec3 color;
out vec2 texCoord;

uniform float scale;

//matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
   //outputs the coords of all vertices
   // gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0); 
   gl_Position = proj * view * model * vec4(aPos, 1.0);
   color = aColor;
   texCoord = aTex;
}