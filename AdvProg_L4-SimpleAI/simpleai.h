#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
 
#include "util.h"

using namespace std;

int readMaxGuess();
int readWordLen();
static vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary);
static char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars);
static string getWordMask(char nextChar);
static bool isCorrectChar(char ch, const string& mask);
static bool isWholeWord(const string& mask);
static vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch);

const char MASK_CHAR = '-';