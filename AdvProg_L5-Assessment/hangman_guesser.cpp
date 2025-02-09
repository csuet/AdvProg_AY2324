#include "hangman_guesser.h"

using std::string;
using std::vector;
using std::set;
using std::map;

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars);
map<char, int> countOccurrences(const vector<string>& candidateWords);
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars);
bool wordConformToMask(const string& word, const string& mask, char ch);

HangmanGuesser::HangmanGuesser(std::string wordFilePath)
{
    vocabulary = readWordListFromFile(wordFilePath);
}

void HangmanGuesser::newGame(int wordLen, char mask_char)
{
    MASK_CHAR = mask_char;
    selectedChars.clear();
    ch = 0;
}

char HangmanGuesser::getChar(string mask)
{
    if (selectedChars.empty()) {    // A new game
        filterCandidateWordsByLen(mask.size());
    } else {
        if (isCharInWord(ch, mask)) {   // Guess a correct char
            filterCandidateWordsByMask(mask);
        } else {                        // Incorrect char
            filterCandidateWordsByLastIncorrectChar();
        }
    }

    ch = findBestChar();
    if (ch != 0) selectedChars.insert(ch);
    return ch;
}

void HangmanGuesser::filterCandidateWordsByLen(int wordLen)
{
    candidateWords.clear();
    for (int i=0; i < vocabulary.size(); ++i) {
        if (vocabulary[i].size() == wordLen) {
            candidateWords.push_back(vocabulary[i]);
        }
    }
}

void HangmanGuesser::filterCandidateWordsByMask(string mask)
{
    vector<string> newWords;
    for (vector<string>::const_iterator it = candidateWords.begin(); it != candidateWords.end(); ++it) {
        if (wordConformToMask(*it, mask, ch)) {
            newWords.push_back(*it);
        }
    }
    candidateWords = newWords;
}

void HangmanGuesser::filterCandidateWordsByLastIncorrectChar()
{
    vector<string> newWords;
    for (vector<string>::const_iterator it = candidateWords.begin(); it != candidateWords.end(); ++it) {
        if (!isCharInWord(ch, *it)) {
            newWords.push_back(*it);
        }
    }
    candidateWords = newWords;
}

char HangmanGuesser::findBestChar()
{
    if (candidateWords.size() == 0) {
        return nextCharWhenWordIsNotInDictionary(selectedChars);
    }

    map<char, int> occurrences = countOccurrences(candidateWords);
    char max_char = findMostFrequentChar(occurrences, selectedChars);

    if (max_char == 0) {
        return nextCharWhenWordIsNotInDictionary(selectedChars);
    } else {
        return max_char;
    }
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    for (char c = 'a'; c <= 'z'; ++c) {
        if (charNotInSet(c, selectedChars)) {
            return c;
        }
    }
    return 0;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> occurrences;
    int numOfWords = candidateWords.size();
    int numOfChars = candidateWords[0].size(); // Tat ca cac tu cung do dai
    for (int i = 0; i < numOfWords; ++i) {
        string word = candidateWords[i];
        set<char> charsOfWords;
        for (int j = 0; j < numOfChars; ++j) {
            if (charNotInSet(word[j], charsOfWords)) {
                occurrences[word[j]] += 1;
                charsOfWords.insert(word[j]);
            }
        }
    }
    return occurrences;
}

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char max_char = 0;
    int max_occur = 0;
    for (map<char, int>::const_iterator it = occurrences.begin(); it != occurrences.end(); ++it) {
        if (max_occur < it->second && charNotInSet(it->first, selectedChars) ) {
            max_occur = it->second;
            max_char = it->first;
        }
    }
    return max_char;
}

bool wordConformToMask(const string& word, const string& mask, char ch)
{
    for (int i = 0; i < mask.size(); ++i) {
        if ( (mask[i] == ch && word[i] != ch) || (word[i] == ch && mask[i] != ch) ) {
            return false;
        }
    }
    return true;
}

