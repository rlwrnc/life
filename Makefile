SRC = main.c
OBJ = main

CC = x86_64-w64-mingw32-gcc

INCLUDES = -I/home/rlwrnc/SDL2/include/SDL2 -I/home/rlwrnc/SDL2_image/include/SDL2

LIBS =  -L/home/rlwrnc/SDL2/lib -L/home/rlwrnc/SDL2_image/lib

COMPILER_FLAGS = -Wall
# -Wl,-subsystem,windows
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: $(SRC)
	$(CC) $(SRC) $(INCLUDES) $(LIBS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./bin/$(OBJ)

clean:
	rm ./bin/*.exe
