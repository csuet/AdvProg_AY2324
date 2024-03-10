

User
hoàn thành các hàm sau
ChatGPT
Rất vui được giúp bạn hoàn thành các hàm. Tuy nhiên, bạn chưa cung cấp danh sách các hàm cần hoàn thành. Bạn có thể liệt kê các hàm cần hoàn thành cùng yêu cầu cụ thể cho mỗi hàm được không? Sau đó, tôi sẽ cố gắng hỗ trợ bạn hoàn thành chúng.

User
hoàn thành các hàm sau#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

/***
    Args:
        min (int): left margin of a range
        max (int): right margin of a range
    Returns:
        number (int) : random number in range [min; max]
***/
int generateRandomNumber(const int min, const int max)
{
    srand(time(NULL));
    int n = rand()% min + max ;
    return n;
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile (filePath);
    if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }

    //while ( getline (wordFile, word) ){  // Thong thuong doc tung line. 
                                           // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
                                // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        //cout << word << '\n';
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
bool isCharInWord(const char ch, const string& word)
{
    for(int i=0 ; i < word.size() ; i++)
    {
    	if (ch == word[i]) return true ;
	}
    return false ; 
}

/***
    Args:
        wordList (vector<string>): A list of words
        index (int): an integer number
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;
     if(index >= 0 && index < wordList.size())
     {
     	answer = tolower(wordList[index]) ;
     	return answer ;
 	 }
 	 else 
 	 {
 	 	return "invalid";
	 }
}

/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord){
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord;
    or (char c : answerWord) {
        if (isalpha(c)) {
            secretWord += '-';
        } else {
            secretWord += c; // Keep non-alphabetic characters unchanged
      
    return secretWord;
}

char getInputCharacter() {
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
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    for(int i=0;i<word.size();i++)
    {
    	if(ch==word[i]) secretWord[i] = ch ; 
	}
}

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    chars +=ch;
    
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: increase the value of incorrectGuess by 1
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
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    /*** TODO
        If ch in word:
            update secretWord: call updateSecretWord() function
            update correctChars: call updateEnteredChars() function
        else:
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
     if (isCharInWord(ch, word)) {
        // Update the secret word
        updateSecretWord(secretWord, ch, word);
        // Update the correct characters
        updateEnteredChars(ch, correctChars);
    } else {
        // Update the incorrect guess count
        updateIncorrectGuess(incorrectGuess);
        // Update the incorrect characters
        updateEnteredChars(ch, incorrectChars);
    }
}

ChatGPT
Dưới đây là các hàm đã được hoàn thành dựa trên yêu cầu của bạn:

cpp
Copy code
#include <iostream>
#include "hangman.h"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <ctime>

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;
using std::tolower;

int generateRandomNumber(const int min, const int max)
{
    srand(time(NULL));
    int n = rand() % (max - min + 1) + min;
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
    else
        answer = "invalid";
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
