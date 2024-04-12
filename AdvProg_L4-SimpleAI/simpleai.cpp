#include "simpleai.h"
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

/***
    Args:
        wordLen (int): The desired length of input word
        vocabulary (vector<string>): The vocabulary
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for(int i  =0 ; i < vocabulary.size() ; i++){
        if(vocabulary[i].size() == wordLen){
            answer.push_back(vocabulary[i]);
        }
    }
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    // Create a set to store the characters that have been guessed
    set<char> guessedChars;

    // Iterate through the selected characters
    for (char ch : selectedChars) {
        // If the character is not in the guessed set, add it
        if (guessedChars.find(ch) == guessedChars.end()) {
            guessedChars.insert(ch);
        }
    }

    // Create a map to count the occurrences of each character
    map<char, int> charCount;

    // Iterate through the guessed characters and count their occurrences
    for (char ch : guessedChars) {
        charCount[ch]++;
    }

    // Find the character with the highest occurrence count
    char nextChar;
    int maxCount = 0;
    for (const auto& pair : charCount) {
        if (pair.second > maxCount) {
            nextChar = pair.first;
            maxCount = pair.second;
        }
    }

    // Return the character with the highest occurrence count
    return nextChar;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    for(const string& word : candidateWords){
        for(char ch : word){
            answer[ch]++;
        }
    }
    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int maxCount = 0 ;
    for(pair<char,int> p : occurrences){
        char ch = p.first;
        int count = p.second ;
        if(selectedChars.count(ch) > count){
            answer = ch ;
            maxCount = count;
        }
    }
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    // Step 1: Count occurrences of each character
    map<char, int> charOccurrences;
    for (const string& word : candidateWords) {
        for (char ch : word) {
            // Skip characters that have already been selected
            if (selectedChars.find(ch) == selectedChars.end()) {
                charOccurrences[ch]++;
            }
        }
    }

    // Step 2: Find the character with the highest occurrence
    char bestChar = '\0';
    int maxOccurrences = 0;
    for (const pair<char, int>& p : charOccurrences) {
        char ch = p.first;
        int occurrences = p.second;
        if (occurrences > maxOccurrences) {
            maxOccurrences = occurrences;
            bestChar = ch;
        }
    }

    return bestChar;
}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

/***
    Args:
        ch (char): The predicted character by the AI
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/

bool isCorrectChar(char ch, const string& mask)
{
    bool answer = false;
    for(int i = 0 ; i < mask.size() ; i++){
        if(ch == mask[i]) answer = true;
    }
    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string& mask)
{
     bool answer =true;
    for(int i = 0 ; i < mask.size() ; i++){
        if(!isalpha(mask[i])) return false;
    }
    return answer;
}

/***
    This function should be used to support the filterWordsByMask function below
    Args:
        mask (string): The response mask by the player
        word (string): input word
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True: mask(-ood), char 'd'  vs word(good)

***/
bool wordConformToMask(const string& word, const string& mask, char ch)
{
    if (word.size() != mask.size()) {
        return false;
    }

    for (int i = 0; i < word.size(); ++i) {
        if (mask[i] == '-' && word[i] != ch) {
            return false;
        }
        else if (mask[i] != '-' && mask[i] != word[i]) {
            return false;
        }
    }

    return true;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfiy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;

    for (const string& word : words) {
        if (wordConformToMask(word, mask, ch)) {
            answer.push_back(word);
        }
    }

    return answer;
}