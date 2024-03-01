LIBFLAGS = -lSDL2 -lSDL2_image
all:
	g++ -std=c++11 -c SDL_utils.cpp $(LIBFLAGS)
	g++ -std=c++11 -c Gallery.cpp $(LIBFLAGS)
	g++ -std=c++11 -c Game.cpp $(LIBFLAGS)
	g++ -std=c++11 -c Snake.cpp $(LIBFLAGS)
	g++ -std=c++11 -c main.cpp $(LIBFLAGS)

	g++ -std=c++11 SDL_utils.o  Gallery.o Game.o  Snake.o  main.o -o main $(LIBFLAGS)
	g++ -std=c++11 -c GameTest.cpp $(LIBFLAGS)
	g++ -std=c++11 SDL_utils.o  Gallery.o Game.o  Snake.o GameTest.o  -lcppunit -o GameTest $(LIBFLAGS)
	g++ -std=c++11 -c SnakeTest.cpp $(LIBFLAGS)
	g++ -std=c++11 SDL_utils.o  Gallery.o Game.o  Snake.o SnakeTest.o  -lcppunit -o SnakeTest $(LIBFLAGS)

run:
	chmod +x main
	./main

test:
	chmod +x GameTest
	./GameTest
	chmod +x SnakeTest
	./SnakeTest

clean:
	rm -rf *.o main GameTest SnakeTest