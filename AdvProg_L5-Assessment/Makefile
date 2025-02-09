all:
	g++ -std=c++17 -c main_game.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 -c util.cpp
	g++ -std=c++17 -c hangman_guesser.cpp
	g++ -std=c++17 -c assessment.cpp
	g++ -std=c++17 -c mainTest.cpp

	g++ -std=c++17 util.o main_game.o hangman_guesser.o assessment.o -o main_game
	g++ -std=c++17 util.o main.o hangman_guesser.o assessment.o -o main
	g++ -std=c++17 mainTest.o hangman_guesser.o util.o assessment.o -lcppunit -o mainTest
run:
	chmod +x main
	./main

run_assessment:
	chmod +x main
	./main

test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest main_game
