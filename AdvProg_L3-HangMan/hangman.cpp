#include <iostream>
#include "hangman.h"
#include <ctime>

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;
using std::tolower;

int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    srand(time(NULL));
    int n = rand() % (min-max) + min +1;
    return n;
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile(filePath);
    if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }

    while (wordFile >> word) {
        wordList.push_back(word);
    }
    wordFile.close();

    return wordList;
}

bool isCharInWord(const char ch, const string& word)
{
    for (char c : word) {
        if (tolower(c) == tolower(ch))
            return true;
    }
    return false;
}

string chooseWordFromList(const vector<string>& wordList, int index) 
{
    string answer;
    if (index >= 0 && index < wordList.size())
        answer = wordList[index];
    return answer;
}

string generateHiddenCharacters(string answerWord)
{
    string secretWord;
    for (char c : answerWord) {
        if (isalpha(c)) {
            secretWord += '-';
        } else {
            secretWord += c;
        }
    }
    return secretWord;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    for (int i = 0; i < word.size(); i++) {
        if (tolower(ch) == tolower(word[i]))
            secretWord[i] = word[i];
    }
}

void updateEnteredChars(const char ch, string& chars)
{
    chars += ch;
}

void updateIncorrectGuess(int& incorrectGuess)
{
    incorrectGuess++;
}

void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    if (isCharInWord(ch, word)) {
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars);
    } else {
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars);
    }
}