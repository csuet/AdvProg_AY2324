#ifndef GUARD_util
#define GUARD_util

#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>


int generateRandomNumber(const int min, const int max);
bool isCharInWord(const char ch, const std::string& word);
std::vector<std::string> readWordListFromFile(const std::string& filePath);
bool charNotInSet(char c, const std::set<char>& s);

#endif