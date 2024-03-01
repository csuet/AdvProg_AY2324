#ifndef GUARD_draw
#define GUARD_draw

#include <string>

using namespace std;
const int MAX_MISTAKES = 8;

void printScreen(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars);
void playAnimation(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars);
void printStats(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars);

std::string getDrawing(const int i);
std::string getNextHangman();
std::string getNextStandingman();

#endif