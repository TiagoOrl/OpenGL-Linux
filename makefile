GPP=g++
LIBS= -lglfw
FLAGS= -pthread
HEADERS=include
INCLUDE_CLASSES=main.cpp stb.cpp classes/Camera.cpp classes/shader.cpp classes/VAO.cpp classes/VBO.cpp classes/EBO.cpp classes/Texture.cpp glad.c


render: $(INCLUDE_CLASSES)
	$(GPP) $(FLAGS) -o render $(INCLUDE_CLASSES) -I $(HEADERS) $(LIBS)

cl:
	rm render