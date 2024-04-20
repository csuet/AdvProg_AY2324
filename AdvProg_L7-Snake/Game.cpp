// UPDATE THIS FILE

#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Game.h"

using namespace std;



// set some attributes as default value
// DO NOT CHANGE THIS CONSTRUCTOR
Game::Game(int _width, int _height)
    : width(_width), height(_height), // play screen 
	  squares(_height, vector<CellType>(_width, CELL_EMPTY)), // cell coordinates
      snake(*this, Position(_width/2, _height/2)),  // init snake positin in middle of play screen
      currentDirection(Direction::RIGHT),
      status(GAME_RUNNING),
      score(0)
{
	// add new cheery in game initiation
	addCherry();
}

Game::~Game()
{
    //dtor
}



/*** 
 * PLEASE UPDATE THIS METHOD
 * 
 * When snake moves to a position,
 * if position belongs to BOARD or SNAKE body, status is GAME_OVER
 * if position is having CHERRY :
 * 			- score schoule be increased
 * 			- snake should eat cherry
 * 			- a new cherry should be randomly added
 * otherwise, this position should be assigned as cell of snake 
 *
 * Args:
 * 		pos (Position): position where the snake will move
 * 
 * Returns:
 * 		// none
 * 
***/

void Game::snakeMoveTo(Position pos) {
  if (getCellType(pos) == CELL_BOARD || getCellType(pos) == CELL_SNAKE) {
    status = GAME_OVER;
  } else if (getCellType(pos) == CELL_CHERRY) {
    score++;
    snake.eatCherry(pos); 
    addCherry();
  } else {
    setCellType(pos, CELL_SNAKE);
  }
}

void Game::snakeLeave(Position position) {
  setCellType(position, CELL_EMPTY);
}

bool Game::canChange(Direction current, Direction next) const {
  if (current == UP || current == DOWN) {
    return next != UP && next != DOWN; 
  }
  return next != LEFT && next != RIGHT;
}

void Game::nextStep() {
  while (!inputQueue.empty()) {
    Direction next = inputQueue.front();
    inputQueue.pop();
    
    if (canChange(currentDirection, next)) {
      currentDirection = next;
      break; 
    }
  }

  snake.move(currentDirection);
}

void Game::addCherry() {
  do {
    Position randomPos(rand() % width, rand() % height);
    
    if (getCellType(randomPos) == CELL_EMPTY) {
      setCellType(randomPos, CELL_CHERRY);
      break;
    }
  } while (true);
}

void Game::setCellType(Position pos, CellType cellType) {
  if (pos.isInsideBox(0, 0, width, height)) {
    squares[pos.y][pos.x] = cellType; 
  }
}



// DO NOT change this method
CellType Game::getCellType(Position pos) const
{
	return pos.isInsideBox(0, 0, width, height) ? squares[pos.y][pos.x] : CELL_OFF_BOARD;
}

// DO NOT change this method
vector<Position> Game::getSnakePositions() const
{
    return snake.getPositions();
}

// DO NOT change this method
GameStatus Game::getGameStatus(){
	return status;
}

// DO NOT change this method
int Game::getWidth(){
	return width;
}

// DO NOT change this method
int Game::getHeight(){
	return height;
}

// DO NOT change this method
Snake Game::getSnake(){
	return snake;
}

