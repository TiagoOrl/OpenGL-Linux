    CC=g++
LIBS= -lglfw -lGLU -lGL -lXrandr -lX11 -lrt -ldl
FLAGS= -pthread
INCLUDE_TAG=include

OBJECTS = ./build/stb.o ./build/glad.o ./build/Texture.o ./build/EBO.o ./build/VBO.o ./build/VAO.o ./build/shader.o ./build/Camera.o


render: ${OBJECTS}
	$(CC) main.cpp ${OBJECTS} $(FLAGS) -o render -I $(INCLUDE_TAG) $(LIBS)



./build/Camera.o : ./classes/Camera.cpp
	$(CC) ./classes/Camera.cpp -I $(INCLUDE_TAG) -c -o ./build/Camera.o

./build/shader.o : ./classes/shader.cpp
	$(CC) ./classes/shader.cpp -I $(INCLUDE_TAG) -c -o ./build/shader.o

./build/VAO.o : ./classes/VAO.cpp
	$(CC) ./classes/VAO.cpp -I $(INCLUDE_TAG) -c -o ./build/VAO.o

./build/VBO.o : ./classes/VBO.cpp
	$(CC) ./classes/VBO.cpp -I $(INCLUDE_TAG) -c -o ./build/VBO.o

./build/EBO.o : ./classes/EBO.cpp
	$(CC) ./classes/EBO.cpp -I $(INCLUDE_TAG) -c -o ./build/EBO.o

./build/Texture.o : ./classes/Texture.cpp
	$(CC) ./classes/Texture.cpp -I $(INCLUDE_TAG) -c -o ./build/Texture.o

./build/glad.o : glad.c
	$(CC) glad.c -c -I $(INCLUDE_TAG) -o ./build/glad.o

./build/stb.o : stb.cpp
	$(CC) stb.cpp -c -I $(INCLUDE_TAG) -o ./build/stb.o

cl:
	rm render ./build/*.o