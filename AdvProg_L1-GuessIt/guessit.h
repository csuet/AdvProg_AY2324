#ifndef _GUESSIT_H
#define _GUESSIT_H

int generateRandomNumber();
int getPlayerGuess();
std::string getAnswer(int number, int randomNumber);
bool checkSuccess(std::string answer);
char getPlayerOpinion();
bool checkContinuePlaying(char isContinued);

void playGuessIt();
int run();

#endif