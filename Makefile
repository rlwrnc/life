CC = x86_64-w64-mingw32-gcc

INCLUDES = -I/home/rlwrnc/SDL2/include/SDL2 -I/home/rlwrnc/SDL2_image/include/SDL2

LIBS =  -L/home/rlwrnc/SDL2/lib -L/home/rlwrnc/SDL2_image/lib

COMPILER_FLAGS = -Wall -g
# -Wl,-subsystem,windows
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: life

life: main.o render.o logic.o
	$(CC) $^ $(INCLUDES) $(LIBS) $(LINKER_FLAGS) -o ./bin/$@

%.o: %.c
	$(CC) $(INCLUDES) $(LIBS) $(COMPILER_FLAGS) -c $^

clean:
	rm ./bin/life.exe *.o
