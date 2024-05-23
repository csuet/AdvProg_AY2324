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

void Game::snakeMoveTo(Position position)
{
    // Method to handle snake movement
    if (!position.isInsideBox(0, 0, width, height)) {
        status = GAME_OVER; // Snake hit the wall
        return;
    }
    if (squares[position.y][position.x] == CELL_SNAKE) {
        status = GAME_OVER; // Snake collided with itself
        return;
    }
    if (squares[position.y][position.x] == CELL_CHERRY) {
        score += 10; // Increase score
        snake.eatCherry(); // Make snake eat cherry
        addCherry(); // Add new cherry
    }
    else {
        squares[position.y][position.x] = CELL_SNAKE; // Move snake
        snakeLeave(snake.getPositions()); // Leave the previous tail position
    }
}



/***
 * PLEASE UPDATE THIS METHOD
 * 
 * When all snake body leave a cell, set it as CELL_EMPTY
 * Args:
 * 		position (Position): position where snake will leave
 * Returns:
 * 		// none
 * 
 ***/
void Game::snakeLeave(Position position)
{
    // Method to handle leaving a position
    squares[position.y][position.x] = CELL_EMPTY; // Set position as empty
}



// DO NOT change this method
void Game::processUserInput(Direction direction)
{
    // Add the direction to the input queue
    inputQueue.push(direction);
}


/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 * 
 * check whether the snake can move to the intended direction with the currect direction.
 * If current direction is UP or DOWN, the next direction should not be UP or DOWN
 * if current diection is LEFT or RIGHT, the next direction should not be LEFT or RIGHT
 * 
 * Args:
 * 		current (Direction): current direction of the snake
 * 		next (Direction): the intened direction that snake will move
 * Returns:
 * 		bool: whether the snake can ben changed the direction
 * 
 ***/
bool Game::canChange(Direction current, Direction next) const
{
    // Determine if the snake can change direction
    if ((current == Direction::UP || current == Direction::DOWN) && 
        (next == Direction::UP || next == Direction::DOWN)) {
        return false;
    }
    if ((current == Direction::LEFT || current == Direction::RIGHT) && 
        (next == Direction::LEFT || next == Direction::RIGHT)) {
        return false;
    }
    return true;
}



/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 * 
 * Iterover the input queue from keyboard. 
 * For each input direction, check whether snake can move or not.
 * If the snake can move,  set currentDiection as this input direction.
 * Otherwise, go to the next input direction from input queue
 * 
 * Args:
 * 		// none
 * Returns:
 * 		// none
 * 
 ***/

void Game::nextStep()
{
    // Process input queue
    if (!inputQueue.empty()) {
        Direction nextDirection = inputQueue.front();
        inputQueue.pop();

        if (canChange(currentDirection, nextDirection)) {
            currentDirection = nextDirection;
        }
    }

    // Move snake according to current direction
    snake.move(currentDirection);
}



/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 * 
 * When snake have already eaten a cherry, please add new cherry inside the play screen with random position
 * 
 * Args:
 * 		// none
 * Returns:
 * 		// none
 * 
 ***/

void Game::addCherry()
{
    // Method to add cherry to a random empty cell
    do {
        cherryPosition = Position(rand() % width, rand() % height);
    } while (squares[cherryPosition.y][cherryPosition.x] != CELL_EMPTY);
    squares[cherryPosition.y][cherryPosition.x] = CELL_CHERRY;
}



/***
 * PLEASE UPDATE THIS METHOD
 * 
 * set cell of a position as intended type.
 * 
 * Args:
 * 		pos (Position): a chosen position
 * 		cellType (CellType): cell type of pos
 * Returns:
 * 		// none
 * 
 ***/


void Game::setCellType(Position pos, CellType cellType)
{
  
    if (pos.isInsideBox(0, 0, width, height)) {
  
        squares[pos.y][pos.x] = cellType;
    }
}



void Game::setGameStatus(GameStatus status)
{
    // Set the game status
    this->status = status;
}




// DO NOT change this method
CellType Game::getCellType(Position p) const
{
	return pos.isInsideBox(0, 0, width, height) ? squares[p.y][p.x] : CELL_OFF_BOARD;
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

