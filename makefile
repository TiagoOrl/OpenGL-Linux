GPP=g++
LIBS= -lglfw -lGLU -lGL -lXrandr -lX11 -lrt -ldl
FLAGS= -pthread


render: main.cpp shader.cpp VAO.cpp VBO.cpp EBO.cpp glad.c
	$(GPP) $(FLAGS) -o render main.cpp shader.cpp VAO.cpp VBO.cpp EBO.cpp glad.c $(LIBS)

clear:
	rm render