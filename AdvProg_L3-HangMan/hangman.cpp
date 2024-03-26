#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    return 1;
}

std::vector<std::string> readWordListFromFile(const std::string& filePath)
{
    std::vector<std::string> wordList;
    std::string word;
    std::ifstream wordFile(filePath);
    if (!wordFile.is_open()) {
        throw std::domain_error("Unable to open file");
    }

    while (wordFile >> word) {
        wordList.push_back(word);
    }
    wordFile.close();

    return wordList;
}

bool isCharInWord(const char ch, const std::string& word)
{
    // TODO: return true if ch is in word else return false
    return true;
}

std::string chooseWordFromList(const std::vector<std::string>& wordList, int index)
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    std::string answer;

    return answer;
}

std::string generateHiddenCharacters(const std::string& answerWord)
{
    // TODO: Generate a hidden version of answerWord (e.g., "apple" -> "-----")
    std::string secretWord;
    for (char ch : answerWord) {
        if (std::isalpha(ch)) {
            secretWord += '-';
        }
        else {
            secretWord += ch;
        }
    }
    return secretWord;
}

int main()
{
    // Example usage
    std::string filePath = "wordlist.txt";
    std::vector<std::string> wordList = readWordListFromFile(filePath);

    // Choose a random word from the list
    int randomIndex = generateRandomNumber(0, wordList.size() - 1);
    std::string chosenWord = chooseWordFromList(wordList, randomIndex);

    // Generate the hidden version of the chosen word
    std::string hiddenWord = generateHiddenCharacters(chosenWord);

    std::cout << "Chosen word: " << chosenWord << std::endl;
    std::cout << "Hidden word: " << hiddenWord << std::endl;

    return 0;
}
