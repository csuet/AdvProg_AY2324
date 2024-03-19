#include <iostream>
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
    int n = min + rand()%(max - min + 1);
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
     for (char c : word) {
        if (c == ch) {
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
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    string answer = wordList[index];
    for(size_t i=0;i<answer.size();i++) answer[i]=tolower(answer[i]);
    return answer;
}


/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord){
    string secretWord(answerWord.length(), '-');

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
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ch) {
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
void updateEnteredChars(const char ch, string& chars){
    chars = chars + ch + ' ';
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess){
    incorrectGuess += 1;
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
    if (isCharInWord(ch, word)){
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars);
   }else {
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars);
   }
}

int main() {
    const string filePath = "words.txt"; 
    const int min_index = 0;
    const int max_index = 499;

    // Initialize the game
    vector<string> wordList = readWordListFromFile(filePath);
    int index = generateRandomNumber(min_index, max_index);
    string answerWord = chooseWordFromList(wordList, index);
    string secretWord = generateHiddenCharacters(answerWord);
    string correctChars = "";
    string incorrectChars = "";
    int incorrectGuess = 0;

    // Game loop
    while (incorrectGuess < 7 && secretWord != answerWord) {
        // Display the game state
        cout << "Secret word: " << secretWord << endl;
        cout << "Correct characters: " << correctChars << endl;
        cout << "Incorrect characters: " << incorrectChars << endl;
        cout << "Incorrect guesses remaining: " << 7 - incorrectGuess << endl;

        // Get a character from the player
        cout << "Enter a character: ";
        char ch = getInputCharacter();

        // Process the player's input
        processData(ch, answerWord, secretWord, correctChars, incorrectGuess, incorrectChars);
    }

    // Display the game result
    if (secretWord == answerWord) {
        cout << "Congratulations! You guessed the word." << endl;
    } else {
        cout << "Game over! The word was: " << answerWord << endl;
    }

    return 0;
}