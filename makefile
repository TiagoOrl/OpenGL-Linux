GPP=g++
LIBS= -lglfw -lGLU -lGL -lXrandr -lX11 -lrt -ldl
FLAGS= -pthread
INCLUDE_GLAD=include
INCLUDE_CLASSES=main.cpp shader_classes/shader.cpp shader_classes/VAO.cpp shader_classes/VBO.cpp shader_classes/EBO.cpp glad.c


render: $(INCLUDE_CLASSES)
	$(GPP) $(FLAGS) -o render $(INCLUDE_CLASSES) -I $(INCLUDE_GLAD) $(LIBS)

cl:
	rm render