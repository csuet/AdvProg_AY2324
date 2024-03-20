#include <iostream>
#include "hangman.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;
using std::tolower;

int generateRandomNumber(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
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
    return word.find(ch) != string::npos;
}

string chooseWordFromList(const vector<string>& wordList, int index) 
{
	string s1;
	for(int i = 0;i < wordList[index].size() ; i++)
	{
		s1 += tolower(wordList[index][i]);
	}
    return s1;
}

string generateHiddenCharacters(string answerWord){
    string secretWord(answerWord.length(), '-');
    return secretWord;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
}

void updateEnteredChars(const char ch, string& chars){
    chars += ch;
    chars += " ";
}

void updateIncorrectGuess(int& incorrectGuess){
    ++incorrectGuess;
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