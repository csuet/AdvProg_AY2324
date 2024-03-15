#include <iostream>
#include "hangman.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::ifstream;
using std::string;
using std::vector;

/***
    Args:
        min (int): left margin of a range
        max (int): right margin of a range
    Returns:
        number (int) : random number in range [min; max]
***/
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

/***
    Args:
        ch (char): A character
        word (string): a word
    Returns:
        result (bool) : the character ch is in the word or not.
***/
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

/***
    Args:
        wordList (vector<string>): A list of words
        index (int): an integer number
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string> &wordList, int index)
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    if (index >= 0 && index < wordList.size())
    {
        return wordList[index];
    }
    else
    {
        return "";
    }
}

/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
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

/***
    Args:
        secretWord (string): secret word in hidden form
        ch (char): a charater
        word (string): the answer word
    Returns:
        void
***/
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

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredChars(const char ch, string &chars)
{
    chars += ch;
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int &incorrectGuess)
{
    incorrectGuess++;
}

/***
    Args:
        ch (char): a character that player enter to console
        word (string): answer word that play needs to guess
        secretWord (string): answer word in hidden form
        correctChars (string): a string that stores correct inputs of player
        incorrectGuess (int): a number that stores the number of player's wrong guess
        incorrectChars (string): a string that stores incorrect inputs of player
    Returns:
        void
***/
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
