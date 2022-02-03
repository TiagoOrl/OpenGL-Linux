GPP=g++
LIBS= -lglfw -lGLU -lGL -lXrandr -lX11 -lrt -ldl
FLAGS= -pthread


render: main.cpp shader_classes/shader.cpp shader_classes/VAO.cpp shader_classes/VBO.cpp shader_classes/EBO.cpp glad.c
	$(GPP) $(FLAGS) -o render main.cpp shader_classes/shader.cpp shader_classes/VAO.cpp shader_classes/VBO.cpp shader_classes/EBO.cpp glad.c $(LIBS)

clear:
	rm render