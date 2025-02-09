#ifndef GUARD_hangman_guesser
#define GUARD_hangman_guesser

#include <string>
#include <vector>
#include <map>
#include <set>

#include "util.h"

class HangmanGuesser
{
  public:
    HangmanGuesser(std::string wordFilePath);
    void newGame(int wordLen, char mask_char = '-');
    char getChar(std::string mask);

  private:
    char MASK_CHAR;
    char ch;
    std::set<char> selectedChars;
    std::vector<std::string> candidateWords;
    std::vector<std::string> vocabulary;

  private:
    void filterCandidateWordsByLen(int wordLen);
    void filterCandidateWordsByMask(std::string mask);
    void filterCandidateWordsByLastIncorrectChar();
    char findBestChar();  
    
};

#endif