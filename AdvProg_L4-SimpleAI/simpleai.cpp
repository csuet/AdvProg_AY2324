#include "simpleai.h"
#include "algorithm"

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
    //Write your code here
    size_t n = vocabulary.size();
    for (size_t i = 0; i < n; i++) {
        if (vocabulary[i].size() == wordLen) answer.push_back(vocabulary[i]);
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
    char answer;
    //Write your code here
    for (char i = 'a'; i <= 'z'; ++i)
    {
        if (selectedChars.find(i) == selectedChars.end())
        {
            answer = i;
        }
    }
    return answer;
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
    size_t range = candidateWords.size();
    for (size_t i = 0; i < range; i++) {
        int n = candidateWords[i].size();
        for (int j = 0; j < n; j++) {
            answer[candidateWords[i][j]]++;
        }
    }
    //Write your code here
    // create the map used in the function right below
    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/

bool comp(const pair<char, int> &p1, const pair<char, int> &p2) {
    return p1.second < p2.second;
}
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int maxx = 0;
    map<char, int> unoccur;
    //size_t charsz = selectedChars.size();
        for (pair c : occurrences){
            if (selectedChars.find(c.first) == selectedChars.end() ) {
                unoccur.insert(c);
            }
        }
        map<char, int>::const_iterator it = max_element(unoccur.begin(),unoccur.end(), comp);
        answer = it->first;
    //Write your code here
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
    // please use the function right above 
    char answer;
    if (candidateWords.empty()) {
        answer = nextCharWhenWordIsNotInDictionary(selectedChars);
        return answer;
    }
    map<char, int> occ = countOccurrences(candidateWords);
    answer = findMostFrequentChar(occ, selectedChars);
    //Write your code here
    return answer;
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
    //Write your code here
    int n = mask.size();
    for (int i = 0; i < n; i++) {
        if (mask[i] == ch) {
            answer = true; 
            break;
        }
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
     bool answer = true;
     int n = mask.size();
     for (int i = 0; i < n; i++) {
         if (mask[i] == '-') {
             answer = false;
             break;
         }
     }
    //Write your code here
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
    bool answer = true;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (mask[i] == '-') {
            if (word[i] == ch) {
                answer = false;
                break;
            }
        }
        else {
            if (mask[i] != word[i]) {
                answer = false;
                break;
            }
        }
    }
    //Write your code here
    return answer;
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
    int n = words.size();
    for (int i = 0; i < n; i++) {
        if (wordConformToMask(words[i], mask, ch))
            answer.push_back(words[i]);
    }
    //Write your code here
    return answer;
}
