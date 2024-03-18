#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


#include "guessit.h"

struct TestStruct {
    std::string testName;
    bool expected;
    std::string errorMsg;
};

bool verifyGetAnswer(int number, int randomNumber, std::string answer) {
    std::string myAnswer = getAnswer(number, randomNumber);
    return myAnswer == answer;
}

bool verifyCheckSuccess(std::string answer, bool expected) {
    return checkSuccess(answer) == expected;
}

bool verifyCheckContinuePlaying(char answer, bool expected) {
    return checkContinuePlaying(answer) == expected;
}

bool verifyGetRandomNumber(int randomNumber) {
    if (randomNumber > 0 && randomNumber <= 100) return true;
    else return false;
}

void runTestLoop(TestStruct testCases[], int testSize) {
    int i;
    for (i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        std::cout << testCases[i].expected << std::endl;
        if (testCases[i].expected)
        {
            std::cout << "PASSED \n";
        }
        else
        {
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test: public CPPUNIT_NS::TestCase {
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testMyGenerateRandomNumber);
  CPPUNIT_TEST(testMyGetAnswer);
  CPPUNIT_TEST(testMyCheckSuccess);
  CPPUNIT_TEST(testMycheckContinuePlaying);
  CPPUNIT_TEST(successTestExit);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testMyGenerateRandomNumber(void){
      int testSize = 4;
      std::string sharedName = "[getAnswer test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyGetRandomNumber(generateRandomNumber()), 
            "The number must be in range 1 to 100."
        },
        {
            sharedName + "test normal 2", 
            verifyGetRandomNumber(generateRandomNumber()),  
            "The number must be in range 1 to 100."
        },
        {
            sharedName + "test opposite angle", 
            verifyGetRandomNumber(generateRandomNumber()),
            "The number must be in range 1 to 100."
        },
        {
            sharedName + "test cos(60) and cos(30)", 
            verifyGetRandomNumber(generateRandomNumber()),
            "The number must be in range 1 to 100."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
    //   exit(0);
  }

  void testMyGetAnswer(void) {
      int testSize = 4;
      std::string sharedName = "[getAnswer test] ";
      TestStruct getAnswerTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyGetAnswer(1, 1, "Congratulation! You win."), 
            "Player's number is equal with random number. The answer must be: Congratulation! You win."
        },
        {
            sharedName + "test normal 2", 
            verifyGetAnswer(1, 4, "Your number is lower."), 
            "Player's number is lower than random number. The answer must be: Your number is lower."
        },
        {
            sharedName + "test opposite angle", 
            verifyGetAnswer(99, 100, "Your number is lower."), 
            "Player's number is lower than random number. The answer must be: Your number is lower."
        },
        {
            sharedName + "test cos(60) and cos(30)", 
            verifyGetAnswer(75, 50, "Your number is higher."),  
            "Player's number is higher than random number. The answer must be: Your number is higher."
        },
      };
      runTestLoop(getAnswerTestCases, testSize);
    //   exit(0);
  }

  void testMyCheckSuccess(void) {
      int testSize = 3;
      std::string sharedName = "[checkSuccess test] ";
      TestStruct checkSuccessTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyCheckSuccess("Congratulation! You win.", true), 
            "Player's guess is correct. Should return true."
        },
        {
            sharedName + "test normal 2", 
            verifyCheckSuccess("Your number is lower.", false), 
            "Player's guess is lower. Should return false."
        },
        {
            sharedName + "test normal 3", 
            verifyCheckSuccess("Your number is higher.", false), 
            "Player's guess is higher. Should return false."
        },
      };
      runTestLoop(checkSuccessTestCases, testSize);
    //   exit(0);
  }

  void testMycheckContinuePlaying(void) {
      int testSize = 4;
      std::string sharedName = "[checkContinuePlaying test] ";
      TestStruct checkContinuePlayingTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyCheckContinuePlaying('y', true), 
            "Player's choice is countinue. Should return true."
        },
        {
            sharedName + "test normal 2", 
            verifyCheckContinuePlaying('Y', true), 
            "Player's choice is countinue. Should return true."
        },
        {
            sharedName + "test normal 3", 
            verifyCheckContinuePlaying('n', false), 
            "Player's choice is end. Should return false."
        },
        {
            sharedName + "test normal 4", 
            verifyCheckContinuePlaying('N', false), 
            "Player's choice is end. Should return false."
        },

      };
      runTestLoop(checkContinuePlayingTestCases, testSize);
    //   exit(0);
  }


  void successTestExit(void) {
    std::cout << "all tests passed! \n";
    exit(0);
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main() {
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
