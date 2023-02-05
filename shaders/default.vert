#version 330 core
layout (location = 0) in vec3 aPos; 
layout (location = 1) in vec3 aColor; 
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

// outputs data to the fragment shader
out vec3 color;
out vec2 texCoord;
out vec3 Normal;
out vec3 crntPos;

uniform mat4 camMatrix;
uniform mat4 model;

void main()
{
   crntPos = vec3(model * vec4(aPos, 1.0f));

   //outputs the coords of all vertices
   // gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0); 

   gl_Position = camMatrix * vec4(crntPos, 1.0f);
   color = aColor;
   texCoord = aTex;
   Normal = aNormal;
}