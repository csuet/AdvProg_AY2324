#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// #include "constants.h"
// #include "SDL_utils.h"
// #include "Game.h"
// #include "Gallery.h"

// #include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

#include "SDL_utils.h"
#include "Game.h"
#include "Gallery.h"
#include "Snake.h"
#include "constants.h"
#include <cstdlib>

struct TestStruct
{
  std::string testName;
  bool result;
  bool expected;
  std::string errorMsg;
};

void runTestLoop(TestStruct testCases[], int testSize){
    int i;
    for (i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
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

bool verifyEatCherry(int numOfEatedCherry){
  Game gameTest(BOARD_WIDTH, BOARD_HEIGHT);
  Position start(0, 0);
  Snake snake(gameTest, start);
  for(int numCherry=0; numCherry<numOfEatedCherry; numCherry++){
    snake.eatCherry();
  }
  return numOfEatedCherry == snake.getNumCherry();
}

bool verifyGrowAtFront(int loop){
  Game gameTest(BOARD_WIDTH, BOARD_HEIGHT);
  srand (time(NULL));
  Position start(0, 0);
  Snake snake(gameTest, start);
  
  for(int i=0; i<loop; i++){
    Direction dir = Direction(rand()%4);
    start = start.move(dir);
    snake.growAtFront(start);
  }
  return snake.getHead()->position == start;
}

bool verifyMove(Direction direction, int numCherry){
  Game gameTest(BOARD_WIDTH, BOARD_HEIGHT);
  Position start(3, 5);
  Position newPosition = start.move(direction);
  // gameTest.snakeMoveTo(newPosition);
  Snake snake(gameTest, start);
  for(int i=0; i<numCherry; i++){
    snake.eatCherry();
  }
  snake.move(direction);
  // std::cout<< "\n"<<newPosition.isInsideBox(0,0,BOARD_WIDTH, BOARD_HEIGHT)<<endl;
  // std::cout<< "\nGameOOver: "<< gameTest.isGameOver()<< ", Game Type: "<< gameTest.getCellType(newPosition)<< " "<<newPosition.x << " : "<< newPosition.y <<endl;
  if(gameTest.isGameOver()){
    return snake.getNumCherry() == numCherry && snake.getHead()->position == start && snake.getTail()->position == start;
  }
  else if(numCherry){
    return snake.getNumCherry() == numCherry-1 && snake.getHead()->position == newPosition;
  }
  return snake.getNumCherry() == numCherry && snake.getHead()->position == newPosition && snake.getTail()->position == newPosition;
}

bool verifyInitSnake(Position start){
  Game gameTest(BOARD_WIDTH, BOARD_HEIGHT);
  Snake snake(gameTest, start);
  return snake.getHead()->position == start;
}

bool verifySlideTo(Position newPosition, int numNode){
  Game gameTest(BOARD_WIDTH, BOARD_HEIGHT);
  Position start(0, 0);
  Snake snake(gameTest, start);
  bool flag=false;
  if(numNode == 1){
    snake.slideTo(newPosition);
  }else{
    // add one Node into snake
    snake.growAtFront(newPosition);
    srand (time(NULL));
    for(int i = 0; i<numNode; i++){
      Direction dir = Direction(rand()%4);
      newPosition.move(dir);
      snake.slideTo(newPosition);
    }
  }
  return snake.getHead()->position == newPosition && snake.getTail()->position == newPosition;
}

class Test: public CPPUNIT_NS::TestCase {
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testInitSnake);
  CPPUNIT_TEST(testEatCherry);
  CPPUNIT_TEST(testGrowAtFront);
  CPPUNIT_TEST(testSlideTo);
  CPPUNIT_TEST(testMove);

  CPPUNIT_TEST(successTestExit);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testInitSnake(void){
      int testSize = 5;
      std::string sharedName = "[testInitSnake] ";
      TestStruct initSnakeTestCases[testSize]; 
      srand (time(NULL));
      
      for(int i=0; i<testSize; i++){
        Position start(rand()%(BOARD_WIDTH-2)+1, rand()%(BOARD_HEIGHT-2)+1);
        // std::cout<< start.x << " : "<< start.y << cell << status<< endl;
        std::string errMsg = "Success if position of snake equal start position and game status is true";
        TestStruct testCase;
        testCase.testName = sharedName + "verifyInitSnake";
        testCase.result = verifyInitSnake(start);
        testCase.expected = true;
        testCase.errorMsg = errMsg;
        initSnakeTestCases[i] = testCase;
      }
      runTestLoop(initSnakeTestCases, testSize);
  }
  void testEatCherry(void){
      int testSize = 5;
      std::string sharedName = "[testEatCherry] ";
      TestStruct eatCherryTestCases[testSize] =
        {
          {
            sharedName + "verifyGetNumCherry",
            verifyEatCherry(1),
            true,
            "Success if numOfCherry is one."
          },
          {
            sharedName + "verifyGetNumCherry",
            verifyEatCherry(2),
            true,
            "Success if numOfCherry is two."
          },
          {
            sharedName + "verifyGetNumCherry",
            verifyEatCherry(3),
            true,
            "Success if numOfCherry is three."
          },
          {
            sharedName + "verifyGetNumCherry",
            verifyEatCherry(4),
            true,
            "Success if numOfCherry is four."
          },
          {
            sharedName + "verifyGetNumCherry",
            verifyEatCherry(5),
            true,
            "Success if numOfCherry is five."
          },
        };
        runTestLoop(eatCherryTestCases, testSize);
  }
  void testGrowAtFront(void){
      int testSize = 5;
      std::string sharedName = "[testGrowAtFront] ";
      TestStruct growAtFrontTestCases[testSize] =
        {
          {
            sharedName + "verifyGrowAtFront",
            verifyGrowAtFront(0),
            true,
            "Success if position of snake equal new position"
          },
          {
            sharedName + "verifyGrowAtFront",
            verifyGrowAtFront(1),
            true,
            "Success if snake position equal new position"
          },
          {
            sharedName + "verifyGrowAtFront",
            verifyGrowAtFront(2),
            true,
            "Success if snake position equal new position"
          },
          {
            sharedName + "verifyGrowAtFront",
            verifyGrowAtFront(3),
            true,
            "Success if snake position equal new position"
          },
          {
            sharedName + "verifyGrowAtFront",
            verifyGrowAtFront(4),
            true,
            "Success if snake position equal new position"
          },
        };
        runTestLoop(growAtFrontTestCases, testSize);
  }
  void testSlideTo(void){
      int testSize =5;
      std::string sharedName = "[testSlideTo] ";
      TestStruct slideToTestCases[testSize];
      srand (time(NULL));
      for(int i=0; i<testSize; i++){
        Position moveTo(rand()%(BOARD_WIDTH-2)+1, rand()%(BOARD_HEIGHT-2)+1);
        std::string errMsg = "Success if position of snake equal new position";
        int numNode = rand()%3+1;
        TestStruct testCase;
        testCase.testName = sharedName + "verifySlideTo";
        testCase.result = verifySlideTo(moveTo, numNode);
        testCase.expected = true;
        testCase.errorMsg = errMsg;
        slideToTestCases[i] = testCase;
      }
      runTestLoop(slideToTestCases, testSize);
  }
  void testMove(void){
      int testSize = 5;
      std::string sharedName = "[testMove] ";
      TestStruct MoveTestCases[testSize] =
        {
          {
            sharedName + "verifyMove",
            verifyMove(LEFT, 0),
            true,
            "Success if return is GameOver"
          },
          {
            sharedName + "verifyMove",
            verifyMove(UP, 1),
            true,
            "Success if return is GameOver"
          },
          {
            sharedName + "verifyMove",
            verifyMove(RIGHT, 2),
            true,
            "Success if cherry is 1 and position is (1, 0)"
          },
          {
            sharedName + "verifyMove",
            verifyMove(RIGHT, 3),
            true,
            "Success if cherry is 1 and position is (0, 1)"
          },
          {
            sharedName + "verifyMove",
            verifyMove(DOWN, 0),
            true,
            "Success if cherry is 0 and position is (0, 1)"
          },
        };
      runTestLoop(MoveTestCases, testSize);
  }
  void successTestExit(void) {
    std::cout << "all tests passed! \n";
    
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

  // return result.wasSuccessful() ? 0 : 1;
  return 0;
}