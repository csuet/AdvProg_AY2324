#include <iostream>
#include "hangman.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::ifstream;
using std::string;
using std::vector;

int generateRandomNumber(const int min, const int max)
{
    int number = rand() % (max - min + 1) + min;
    return number;
}

vector<string> readWordListFromFile(const string &filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile(filePath);
    if (!wordFile.is_open())
    {
        throw domain_error("Unable to open file");
    }

    while (wordFile >> word)
    {
        wordList.push_back(word);
        cout << word << '\n';
    }
    wordFile.close();

    return wordList;
}

bool isCharInWord(const char ch, const string &word)
{
    for (char c : word)
    {
        if (c == ch)
        {
            return true;
        }
    }
    return false;
}

string chooseWordFromList(const vector<string> &wordList, int index)
{
    if (index >= 0 && index < wordList.size())
    {
        string word = wordList[index];

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }
    else
    {
        return "";
    }
}

string generateHiddenCharacters(string answerWord)
{
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord(answerWord.length(), '-');
    return secretWord;
}

char getInputCharacter()
{
    char ch;
    cin >> ch;
    return tolower(ch);
}

void updateSecretWord(string &secretWord, const char ch, const string &word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ch)
        {
            secretWord[i] = ch;
        }
    }
}

void updateEnteredChars(const char ch, string &chars)
{
    chars.push_back(ch);
    chars.push_back(' ');
}

void updateIncorrectGuess(int &incorrectGuess)
{
    incorrectGuess++;
}

void processData(const char ch, const string &word,
                 string &secretWord,
                 string &correctChars,
                 int &incorrectGuess, string &incorrectChars)
{
    if (isCharInWord(ch, word))
    {
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars);
    }
    else
    {
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars);
    }
}
