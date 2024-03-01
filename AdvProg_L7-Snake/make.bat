set OBJS=main.cpp Snake.cpp Game.cpp Gallery.cpp SDL_utils.cpp
set OBJ_NAME=main.exe
set COMPILER_FLAGS=-std=c++11 
set LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
set INCLUDE_DIR=-Isrc/include -Lsrc/lib
set LIB_DIR=-Isrc/include -Lsrc/lib

g++ %COMPILER_FLAGS% %INCLUDE_DIR% %LIB_DIR% %OBJS% %LINKER_FLAGS% -o %OBJ_NAME%
