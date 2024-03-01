#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "hangman.h"
#include <string>

using std::string;

struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool verifyGenerateRandomNumber(const int min, const int max) {
    int myAnswer = generateRandomNumber(min, max);
    return (myAnswer >= min && myAnswer <= max);
}

bool verifyIsCharInWord(const char ch, const string& word){
    return isCharInWord(ch, word);
}

bool verifyChooseWordFromList(const vector<string>& wordList, int index, string correctWord){
    string myAnswer = chooseWordFromList(wordList, index);
    return (myAnswer == correctWord);
}

bool verifyUpdateSecretWord(string secretWord, const char ch, const string word, string answer) {
    updateSecretWord(secretWord, ch, word);
    return secretWord == answer;
}

bool verifyUpdateEnteredChars(const char ch, string chars, string answer) {
    updateEnteredChars(ch, chars);
    return chars == answer;
}

int verifyUpdateIncorrectGuess(int incorrectGuess) {
    updateIncorrectGuess(incorrectGuess);
    return incorrectGuess;
}

bool verifyProcessData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars){
    string preCorrectChars = correctChars;
    string preSecretWord = secretWord;
    int preIncorrectGuess = incorrectGuess;
    string preIncorrectChars = incorrectChars;
    processData(ch, word, secretWord, correctChars, incorrectGuess, incorrectChars);
    if (word.find_first_of(ch) != string::npos){
        return (correctChars.length() > preCorrectChars.length()) && (secretWord != preSecretWord);
    }else{
        return (preIncorrectGuess+1 == incorrectGuess) && (incorrectChars.length() > preIncorrectChars.length());
    }
}

bool verifyGenerateHiddenCharacters(string secretWord, string answer) {
    string myAnswer = generateHiddenCharacters(secretWord);
    return myAnswer == answer;
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
    CPPUNIT_TEST(testGenerateRandomNumber);
    CPPUNIT_TEST(testIsCharInWord);
    CPPUNIT_TEST(testChooseWordFromList);
    CPPUNIT_TEST(testProcessData);
    CPPUNIT_TEST(testUpdateSecretWord);
    CPPUNIT_TEST(testUpdateEnteredChars);
    CPPUNIT_TEST(testUpdateIncorrectGuess);
    CPPUNIT_TEST(testGenerateHiddenCharacters);
    CPPUNIT_TEST(successTestExit);
    CPPUNIT_TEST_SUITE_END();

    public:
      void setUp(void) {}
      void tearDown(void) {}

    protected:
      void testGenerateRandomNumber(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkGenerateRandomNumber test] ";
        TestStruct checkGenerateRandomNumber[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyGenerateRandomNumber(0, 10), 
                true,
                "Should return an integer number between 0 and 10\n"
            },
            {
                sharedName + "test normal 2", 
                verifyGenerateRandomNumber(15, 50), 
                true,
                "Should return an integer number between 15 and 50\n"
            },
            {
                sharedName + "test normal 3", 
                verifyGenerateRandomNumber(1, 100), 
                true,
                "Should return an integer number between 1 and 100\n"
            },
            {
                sharedName + "test normal 4", 
                verifyGenerateRandomNumber(1003, 2022), 
                true,
                "Should return an integer number between 1003 and 2022\n"
            },
            {
                sharedName + "test normal 5", 
                verifyGenerateRandomNumber(10, 10), 
                true,
                "Should return an integer number between 10 and 10\n"
            },
        };
        runTestLoop(checkGenerateRandomNumber, testSize);
      }

      void testIsCharInWord(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkIsCharInWord test] ";
        TestStruct checkIsCharInWord[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyIsCharInWord('a', "dad"), 
                true,
                "Character 'a' exists in word dad. Should return true\n"
            },
            {
                sharedName + "test normal 2", 
                verifyIsCharInWord('a', "mom"), 
                false,
                "Character 'a' doesn't exist in word mom. Should return false\n"
            },
            {
                sharedName + "test normal 3", 
                verifyIsCharInWord('g', "strange"), 
                true,
                "Character 'g' exists in word strange. Should return true\n"
            },
            {
                sharedName + "test normal 4", 
                verifyIsCharInWord('m', "mommy"), 
                true,
                "Character 'm' exists in word mommy. Should return true\n"
            },
            {
                sharedName + "test normal 5", 
                verifyIsCharInWord('b', "animal"), 
                false,
                "Character 'b' doesn't exist in word animal. Should return false\n"
            },
        };
        runTestLoop(checkIsCharInWord, testSize);
      }

      void testChooseWordFromList(void) {
        const int testSize = 5;
        vector<string> wordList;
        wordList.push_back("MoM");
        wordList.push_back("Dad");
        wordList.push_back("faTher");
        wordList.push_back("Mother");
        wordList.push_back("FAMILY");
        std::string sharedName = "\n[checkChooseWordFromList test] ";
        TestStruct checkChooseWordFromList[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyChooseWordFromList(wordList, 1, "dad"), 
                true,
                "Word 'dad' is in index 1 in the list. Should return dad\n"
            },
            {
                sharedName + "test normal 2", 
                verifyChooseWordFromList(wordList, 0, "mom"), 
                true,
                "Word 'mom' is in index 0 in the list. Should return mom\n"
            },
            {
                sharedName + "test normal 3", 
                verifyChooseWordFromList(wordList, 4, "family"), 
                true,
                "Word 'family' is in index 4 in the list. Should return family\n"
            },
            {
                sharedName + "test normal 4", 
                verifyChooseWordFromList(wordList, 3, "mother"), 
                true,
                "Word 'mother' is in index 3 in the list. Should return mother\n"
            },
            {
                sharedName + "test normal 5", 
                verifyChooseWordFromList(wordList, 2, "father"), 
                true,
                "Word 'father' is in index 2 in the list. Should return father\n"
            },
        };
        runTestLoop(checkChooseWordFromList, testSize);
      }

      void testUpdateSecretWord(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkUpdateSecretWord test] ";
        TestStruct checkUpdateSecretWord[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyUpdateSecretWord("-", 'a', "a", "a"), 
                true,
                "Character 'a' exist in secret word. Should return string 'a'."
            },
            {
                sharedName + "test normal 2", 
                verifyUpdateSecretWord("--t", 'c', "cat", "c-t"), 
                true,
                "Character 'c' exist in secret word. Should return string 'c-t'."
            },
            {
                sharedName + "test normal 3", 
                verifyUpdateSecretWord("ca---ag-", 'r', "carriage", "carr-ag-"), 
                true,
                "Character 'r' exist in secret word. Should return string 'carr-ag-'."
            },
            {
                sharedName + "test normal 4", 
                verifyUpdateSecretWord("s-iss--s", 's', "scissors", "s-iss--s"), 
                true,
                "Character 's' existed in secret word. Should return string 's-iss--s'."
            },
            {
                sharedName + "test normal 5", 
                verifyUpdateSecretWord("circumsta-ce", 'n', "circumstance", "circumstance"), 
                true,
                "Character 'n' exist in secret word. Should return string 'circumstance'."
            },
        };
        runTestLoop(checkUpdateSecretWord, testSize);
      }

    void testUpdateEnteredChars(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkUpdateEnteredChars test] ";
        TestStruct checkUpdateEnteredChars[testSize]  = 
        {
          {
              sharedName + "test normal 1", 
              verifyUpdateEnteredChars('a', "s ", "s a "), 
            true,
            "Character 'a' is correct character. Should return string 's a '."
        },
        {
            sharedName + "test normal 2", 
            verifyUpdateEnteredChars('a', "a ", "a a "), 
            true,
            "Character 'a' is correct character. Should return string 'a a '."
        },
        {
            sharedName + "test normal 3", 
            verifyUpdateEnteredChars('r', "c a i a g e ", "c a i a g e r "), 
            true,
            "Character 'r' is correct character. Should return string 'c a i a g e r '."
        },
        {
            sharedName + "test normal 4", 
            verifyUpdateEnteredChars('o', "s c i ", "s c i o "), 
            true,
            "Character 'o' is correct character. Should return string 's c i o '."
        },
        {
            sharedName + "test normal 5", 
            verifyUpdateEnteredChars('n', "", "n "), 
            true,
            "Character 'n' is correct character. Should return string 'n '."
        },
      };
      runTestLoop(checkUpdateEnteredChars, testSize);
    }

    void testUpdateIncorrectGuess(void) {
        const int testSize = 5;
        std::string sharedName = "[checkUpdateIncorrectGuess test] ";
        std::cout << "\n>> Testing the UpdateIncorrectGuess() function"<< std::endl;
        for(int incorrectGuess = 0; incorrectGuess < 5; incorrectGuess++){
            // TestStruct res;
            int youGot = verifyUpdateIncorrectGuess(incorrectGuess);
            int expected = incorrectGuess+1;
            if (youGot == expected){
                std::cout << sharedName << " test normal 1: "<< "PASSED!"<< std::endl; 
            }else{
                std::cout << sharedName << " test normal 1: "<< "FAILED!"<< std::endl;
                std::cout << "The current mistake is "<< incorrectGuess<< "! Got: " << youGot << ", Expected: "<< expected << " !"; 
                exit(1);
            }
        }
    }

    void testProcessData(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkProcessData test] ";
        const string word = "strange";
        string secretWord = "-------";
        string correctChars = "";
        string incorrectChars = "";
        int incorrectGuess = 0;
        TestStruct checkProcessData[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyProcessData('a', word, secretWord, correctChars, incorrectGuess, incorrectChars), 
                true,
                "Character 'a' exists in word strange. secretWord and correctChars should be updated\n"
            },
            {
                sharedName + "test normal 2", 
                verifyProcessData('b', word, secretWord, correctChars, incorrectGuess, incorrectChars), 
                true,
                "Character 'b' doesn't exist in word strange. incorrectGuess and incorrectChars should be updated\n"
            },
            {
                sharedName + "test normal 3", 
                verifyProcessData('k', word, secretWord, correctChars, incorrectGuess, incorrectChars), 
                true,
                "Character 'k' doesn't exists in word strange. incorrectGuess and incorrectChars should be updated\n"
            },
            {
                sharedName + "test normal 4", 
                verifyProcessData('e', word, secretWord, correctChars, incorrectGuess, incorrectChars), 
                true,
                "Character 'e' exists in word strange. secretWord and correctChars should be updated\n"
            },
            {
                sharedName + "test normal 5", 
                verifyProcessData('t', word, secretWord, correctChars, incorrectGuess, incorrectChars), 
                true,
                "Character 't' exists in word strange. secretWord and correctChars should be updated\n"
            },
        };
        runTestLoop(checkProcessData, testSize);
    }

    void testGenerateHiddenCharacters(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkGenerateHiddenCharacters test] ";
        TestStruct checkGenerateHiddenCharacters[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyGenerateHiddenCharacters("a", "-"), 
                true,
                "Secret Word is 'a'. Should return string '-'."
            },
            {
                sharedName + "test normal 2", 
                verifyGenerateHiddenCharacters("cat", "---"), 
                true,
                "Secret Word is 'cat'. Should return string '---'."
            },
            {
                sharedName + "test normal 3", 
                verifyGenerateHiddenCharacters("carriage", "--------"), 
                true,
                "Secret Word is 'carriage'. Should return string '--------'."
            },
            {
                sharedName + "test normal 4", 
                verifyGenerateHiddenCharacters("scissors", "--------"), 
                true,
                "Secret Word is 'scissors'. Should return string '--------'."
            },
            {
                sharedName + "test normal 5", 
                verifyGenerateHiddenCharacters("circumstance", "------------"), 
                true,
                "Secret Word is 'circumstance'. Should return string '------------'."
            },
        };
        runTestLoop(checkGenerateHiddenCharacters, testSize);
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
