#include <iostream>
#include <string>

#include "util.h"
#include "hangman_guesser.h"

using namespace std;

const char MASK_CHAR = '-';

int readMaxGuess();
int readWordLen();
string getWordMask(char nextChar);
bool isCorrectChar(char ch, const string& mask);
bool isWholeWord(const string& mask);

int main()
{
    // B0
    //string wordFilePath = "data/hangman_wordlist.txt";
    string wordFilePath = "data/hangman_dictionary.txt";
    HangmanGuesser hmGuesser(wordFilePath);
    /*
    vector<string> vocabulary;
    vocabulary.push_back("hello");
    vocabulary.push_back("good");
    vocabulary.push_back("bad");
    vocabulary.push_back("world");
    vocabulary.push_back("nice");
    */

    // B1
    int maxGuess = readMaxGuess();
    int wordLen = readWordLen();

    hmGuesser.newGame(wordLen, MASK_CHAR);
    string mask = string(wordLen, MASK_CHAR);
    cout << "So your secret word looks like: " << mask << endl;

    int incorrectGuess = 0;
    string finalMessage = "";
    //cout << "Max guess: " << incorrectGuess << " Word-len: " << wordLen << " Word num: " << candidateWords.size() << endl;

    while (true) {
        // B2
        char nextChar = hmGuesser.getChar(mask);
        if (nextChar == 0) {
            finalMessage =  "There is something wrong. I quit :|";
            break;
        }
        mask = getWordMask(nextChar);

        // B3
        if (isCorrectChar(nextChar, mask)) {
            if (isWholeWord(mask)) {
                finalMessage =  "It is easy :)";
                break;
            }
        } else {
            incorrectGuess += 1;
            cout << "Incorrect guess count: " << incorrectGuess << endl;

            if (maxGuess <= incorrectGuess) {
                finalMessage = "Maybe, you should give me more times to guess :(";
                break;
            }
        }
    }

    // B4
    cout << finalMessage << endl;
    return 0;
}

int readMaxGuess()
{
    int maxGuess;
    cout << endl << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;

}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}
