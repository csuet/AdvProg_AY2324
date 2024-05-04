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
    for (const string& word : vocabulary) {
        if (word.length() == wordLen) {
            answer.push_back(word);
        }
    }
    return answer;
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    // Write your code here
    char answer;
    char answer = *selectedChars.begin();
    return answer;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    // Write your code here
    for (const auto& word : candidateWords) {
        for (const auto& c : word) {
            ++ answer[c];
        }
    }
    return answer;
}

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    // Write your code here
    char answer;
    int cntAnswer = 0;
    //Write your code here
    for (const auto& [c, cnt] : occurrences) {
        if (selectedChars.find(c) != selectedChars.end()) continue;
        if (cnt > cntAnswer) {
            cntAnswer = cnt;
            answer = c;
        }
    }
    return answer;
}

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    // Write your code here
    map<char, int> cnt = countOccurrences(candidateWords);
    answer = findMostFrequentChar(cnt, selectedChars);
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

bool isCorrectChar(char ch, const string& mask)
{
    bool answer;
    // Write your code here
    bool answer;
    bool answer = false;
    //Write your code here
    for (const auto& c : mask) {
        if (ch == c) answer = true;
    }
    return answer;
}

bool isWholeWord(const string& mask)
{
    // Write your code here
     bool answer;
     bool answer = true;
    for (const auto& c : mask) {
        if (c == '_' || c == '-') answer = false;
    }
    return answer;
}

bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer;
    // Write your code here
    if ((int) word.size() != (int) mask.size()) return false;
    for (int i = 0; i < (int) word.size(); ++ i) {
        if (mask[i] == '_' || mask[i] == '-') continue;
        if (mask[i] != word[i]) return false;
    }
    for (int i = 0; i < (int) word.size(); ++ i) {
        if (word[i] == ch) return true;
    }
    return answer;
}

vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    // Write your code here
    for (const auto& word : words) {
        if (wordConformToMask(word, mask, ch) == true) answer.push_back(word);
    }
    return answer;
}
