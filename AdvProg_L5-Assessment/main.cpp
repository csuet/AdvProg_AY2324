#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "hangman_guesser.h"
#include "assessment.h"

using namespace std;

int main()
{
    //string vocabularyFilePath = "data/hangman_wordlist.txt";
    string vocabularyFilePath = "data/hangman_dictionary.txt";
    HangmanGuesser hmGuesser(vocabularyFilePath);

    string testFilePath = "data/Ogden_Picturable_200.txt";
    vector<string> testWords = {"lemon", "apple", "banana", "orange", "pear", "grape", "strawberry", "watermelon",};

    vector<MistakeByWord> mistakeList;
    vector<string> unsolvableList;
    getMistakeByWordList(mistakeList, unsolvableList, testWords, hmGuesser);

    sort(mistakeList.begin(), mistakeList.end()); // http://stackoverflow.com/questions/4892680/sorting-a-vector-of-structs
    int totalMistake = 0;
    for (int i = 0; i < mistakeList.size(); ++i) {
        totalMistake += mistakeList[i].count;
        cout << i+1 << ". " << mistakeList[i].word << " " << mistakeList[i].count << endl;
    }

    int solvableCount = testWords.size() - unsolvableList.size();
    cout << "Average misktake: " << (double) totalMistake / (double) solvableCount << endl;

    if (unsolvableList.size()) {
        cout << "Number of unsolvable words: " << unsolvableList.size()  << endl;
        for (int i = 0; i < unsolvableList.size(); ++i) {
            cout << unsolvableList[i] << " ";
        }
        cout << endl;
    } else {
        cout << "All words can be solved." << endl;
    }

    return 0;
}

