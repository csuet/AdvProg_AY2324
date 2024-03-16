
all:
	g++ -std=c++17 -c guessit.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 guessit.o main.o -o main
run:
	chmod +x main
	./main
test:
	chmod +x guessitTest
	./guessitTest
clean:
	rm -rf *.o guessit guessitTest