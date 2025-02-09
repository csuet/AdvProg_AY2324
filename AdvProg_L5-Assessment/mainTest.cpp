#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <fstream>
#include "assessment.h"
#include "util.h"
#include <string>
#include <algorithm>

using std::string, std::ifstream;
using namespace std;



struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool verifyCompareMistakeByWord(MistakeByWord & m1, MistakeByWord& m2){
    return m1 < m2;
}

bool verifyGetMistakeByWordList(vector<struct MistakeByWord> mistakeList,
                                            vector <string> unsolvableList,
                                            vector <string> testWords,
                                            HangmanGuesser hmGuesser,
                                            vector<struct MistakeByWord> expectedList) {
    getMistakeByWordList(mistakeList, unsolvableList, testWords, hmGuesser);
    sort(mistakeList.begin(), mistakeList.end());
    if (mistakeList.size() != expectedList.size()) {
        return false;
    }
    for (int i = 0; i < mistakeList.size(); i++) {
        if (mistakeList[i].count != expectedList[i].count || mistakeList[i].word != expectedList[i].word) {

            if (mistakeList[i].word != expectedList[i].word) {
                cout << "\nExpected: '" << expectedList[i].word << "' at index " << i
                     << " ,but got '" << mistakeList[i].word <<"'" << endl;

            }
            else {
                cout << "\ncount mismatch for word: "<< expectedList[i].word << endl;

            }

            return false;
        }
    }
    return true;
}
bool verifyCountMistakes(const string& testWord, int expectedNumError, HangmanGuesser hmGuesser) {
    int numError = countMistakes(testWord, hmGuesser);
    if (numError != expectedNumError) {
        cout << "Expected: " << expectedNumError << " but got " << numError <<" for word '" << testWord <<"'" << endl;
        return false;
    }
    return true;
}
bool verifyUpdateMask(string testWord, char character, string expectedMask) {
    string mask = string(testWord.size(), '-');
    updateMask(mask, character, testWord);
    if (mask != expectedMask) {
        cout << " Expected: '" << expectedMask << "' but got '" << mask << "' for word '" << testWord << "' and character '" << character << "'" << endl;
        return false;
    }
    return true;
}



void runTestLoop(TestStruct testCases[], int testSize){
    for (int i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << "PASSED!";
        }
        else
        {
            std::cout << "FAILED!\n";
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testCompareMistakeByWord);
    CPPUNIT_TEST(testCountMistakes);
    CPPUNIT_TEST(testUpdateMask);
    CPPUNIT_TEST(testGetMistakeByWordList);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void) {}
    void tearDown(void) {}

protected:
    void testCompareMistakeByWord(void){
        const int testSize = 5;
        std::string sharedName = "\n[test operator < for struct MistakeByWord] ";
        auto wordCounter1 = MistakeByWord{1,"a"};
        auto wordCounter2 =MistakeByWord{2,"a"};
        auto wordCounter3 =MistakeByWord{1,"b"};
        auto wordCounter4 =MistakeByWord{1,"bbbbb"};
        TestStruct testCompareMistakeByWord[testSize]  =
                {
                        {
                                sharedName + "test normal 1",
                                verifyCompareMistakeByWord(wordCounter1, wordCounter2),
                                true,
                                "The MistakeByWord compare 2 struct firstly by it's count, "
                                "then the word itself\n"
                        },
                        {
                                sharedName + "test normal 2",
                                verifyCompareMistakeByWord(wordCounter1,
                                                           wordCounter3),
                                true,
                                "The MistakeByWord compare 2 struct firstly by it's count,"
                                "                                \"then the word itself\\n"
                        },
                        {
                                sharedName + "test normal 3",
                                verifyCompareMistakeByWord(wordCounter1,
                                                           wordCounter4),
                                true,
                                "The MistakeByWord compare 2 struct firstly by it's count,"
                                " then the word itself\n"
                        },
                        {
                                sharedName + "test normal 4",
                                verifyCompareMistakeByWord(wordCounter4,
                                                           wordCounter1),
                                false,
                                "The MistakeByWord compare 2 struct firstly by it's count,"
                                " then the word itself\n"
                        },
                        {
                                sharedName + "test normal 5",
                                verifyCompareMistakeByWord(wordCounter4,
                                                           wordCounter3),
                                false,
                                "The MistakeByWord compare 2 struct firstly by it's count,"
                                " then the word itself\n"
                        }
                };
        runTestLoop(testCompareMistakeByWord, testSize);
    }
    void testGetMistakeByWordList(void) {
        const int testSize = 2;
        std::string sharedName = "\n[test function GetMistakeByWordList] ";
        string testFilePath = "data/Ogden_Picturable_200.txt";
        vector<string> testWords1 = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};
        vector<string> fruitWords1 = {"lemon", "apple", "banana", "orange", "pear", "grape", "strawberry", "watermelon",};
        vector<struct MistakeByWord> expectedRandomList1 = {
                {5, "def"},
                {8, "ghi"},
                {10, "abc"},
                {13, "jkl"},
                {14, "mno"},
                {18, "pqr"},
                {18, "stu"},
                {23, "vwx"},
                {24, "yz"}
        };
        vector<struct MistakeByWord> expectedFruitList1 = {
                {0, "watermelon"},
                {1, "banana"},
                {1, "strawberry"},
                {3, "grape"},
                {3, "orange"},
                {4, "lemon"},
                {5, "apple"},
                {6, "pear"},

        };
        vector<MistakeByWord> mistakeList;
        vector<string> unsolvableList;
        string vocabularyFilePath = "data/hangman_dictionary.txt";
        HangmanGuesser hmGuesser(vocabularyFilePath);
        TestStruct testGetMistakeByWordList[testSize]  =
                {
                        {
                                sharedName + "random word 1",
                                verifyGetMistakeByWordList(mistakeList,
                                                           unsolvableList,
                                                           testWords1,
                                                           hmGuesser,
                                                           expectedRandomList1),
                                true,
                                "Count number of mistake for each word and sort the list\n"
                        },
                        {
                                sharedName + "fruit word 1",
                                verifyGetMistakeByWordList(mistakeList,
                                                           unsolvableList,
                                                           fruitWords1,
                                                           hmGuesser,
                                                           expectedFruitList1),
                                true,
                                "Count number of mistake for each word and sort the list\n"
                        }
                };
        runTestLoop(testGetMistakeByWordList, testSize);
    }
    void testCountMistakes(void) {
        const int testSize = 5;
        std::string sharedName = "\n[test function CountMistakes] ";
        string vocabularyFilePath = "data/hangman_dictionary.txt";
        HangmanGuesser hmGuesser(vocabularyFilePath);
        TestStruct testCountMistakes[testSize]  =
                {
                        {
                                sharedName + "count 1",
                                verifyCountMistakes("banana",1,hmGuesser),
                                true,
                                "Should return number of mistake character in given word and default guesser \n"
                        },
                        {
                                sharedName + "count 2",
                                verifyCountMistakes("apple",5,hmGuesser),
                                true,
                                "Should return number of mistake character in given word and default guesser \n"
                        },
                        {
                                sharedName + "count 3",
                                verifyCountMistakes("aawc",20,hmGuesser),
                                true,
                                "Should return number of mistake character in given word and default guesser \n"
                        },
                        {
                                sharedName + "count 4",
                                verifyCountMistakes("kiwi",4,hmGuesser),
                                true,
                                "Should return number of mistake character in given word and default guesser \n"
                        },
                        {
                                sharedName + "count 5",
                                verifyCountMistakes("number",6,hmGuesser),
                                true,
                                "Should return number of mistake character in given word and default guesser \n"
                        }
                };
        runTestLoop(testCountMistakes, testSize);
    }
    void testUpdateMask(void) {
        const int testSize = 5;
        std::string sharedName = "\n[test function UpdateMask] ";
        TestStruct testUpdateMask[testSize]  =
                {
                        {
                                sharedName + "test word 1",
                                verifyUpdateMask("lemon",'e',"-e---"),
                                true,
                                "Should mask characters that differs from given char by -\n"
                        },
                        {
                                sharedName + "test word 2",
                                verifyUpdateMask("apple",'e',"----e"),
                                true,
                                "Should mask characters that differs from given char by -\n"
                        },
                        {
                                sharedName + "test word 3",
                                verifyUpdateMask("aawc",'a',"aa--"),
                                true,
                                "Should mask characters that differs from given char by -\n"
                        },
                        {
                                sharedName + "test word 4",
                                verifyUpdateMask("kiwi",'i',"-i-i"),
                                true,
                                "Should mask characters that differs from given char by -\n"
                        },
                        {
                                sharedName + "test word 5",
                                verifyUpdateMask("number",'e',"----e-"),
                                true,
                                "Should mask characters that differs from given char by -\n"
                        }

                };
        runTestLoop(testUpdateMask, testSize);
    }

    void successTestExit(void) {
        std::cout << "all tests passed! \n";
        exit(0);
    }
};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
    CPPUNIT_NS::TestResult controller;

    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    return result.wasSuccessful() ? 0 : 1;
}
