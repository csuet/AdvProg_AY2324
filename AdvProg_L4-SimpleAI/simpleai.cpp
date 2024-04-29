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


vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    int n = vocabulary.size();
    //Write your code here
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( vocabulary[i].length() == wordLen )
        {
            answer.push_back(vocabulary[i]);
        }
    }
    return answer;
}


char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    //Write your code here
    char answer = *selectedChars.begin();
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
    //Write your code here
    int n = candidateWords.size();
    for ( int i = 0 ; i < n ; i++ )
    {
       int m = candidateWords[i].length();
       string word = candidateWords[i];
       for ( int j = 0 ; j < m ; j++ )
       {
           ++answer[word[j]];
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
    //Write your code here
    int n = 0 ;
    for (const auto& [a, m] : occurrences) {
        if (selectedChars.find(a) != selectedChars.end()) continue;
        if (m > n) {
            n = m;
            answer = a;
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
    char answer;
    //Write your code here
    map<char,int> n = countOccurrences(candidateWords);
    answer = findMostFrequentChar(n,selectedChars);
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
    //Write your code here
    bool answer = false;
    for ( int i = 0 ; i < (int) mask.length() ; i++ )
    {
        if(mask[i]==ch) answer = true;
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
    //Write your code here
    for ( int i = 0 ; i < (int) mask.length() ; i++ )
    {
        if(mask[i]=='_' ||mask[i]=='-' ) answer = false;
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
    bool answer;
    //Write your code here
    if ((int) word.size() != (int) mask.size()) return false;
    for (int i = 0; i < (int) word.size(); ++ i) {
        if (mask[i] == '_' || mask[i] == '-') continue;
        if (mask[i] != word[i]) return false;
    }
    for (int i = 0; i < (int) word.size(); ++ i) {
        if (word[i] == ch) return true;
    }
    return false;
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
    //Write your code here
    for ( int i = 0 ; i < (int)words.size() ; i++ )
    {
        if (wordConformToMask(words[i], mask, ch) == true) answer.push_back(words[i]);
    }
    return answer;
}
