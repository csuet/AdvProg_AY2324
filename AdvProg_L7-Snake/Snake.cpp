
#include "Snake.h"
#include "Game.h"
#include <iostream>

// set some attributes as default value
// DO NOT CHANGE THIS CONSTRUCTOR
Snake::Snake(Game& _game, Position start)
    : head(new SnakeNode(start)), tail(head), game(_game), cherry(0)
{
    // Using Game.snakeMoveTo method to move Snake to start position;
    game.snakeMoveTo(start);    
}

// set some attributes as default value
// PLEASE UPDATE THIS METHOD

Snake::~Snake()
{
    // Loop through the snake nodes and delete them
    SnakeNode* p = tail;
    while (p != nullptr) {
        SnakeNode* nextNode = p->next;
        delete p;
        p = nextNode;
    }
}

// DO NOT CHANGE METHOD
vector<Position> Snake::getPositions() const
{
    vector<Position> res;
    for (SnakeNode* p = tail; p != nullptr; p = p->next)
        res.push_back(p->position);
    return res;
}

/*** 
 * PLEASE UPDATE THIS METHOD
 * 
 * When snake moves to a position,
 *  head->next = ...
 *  head = head->next;
 * Args:
 * 		pos (newPosition): head of snake grow at new position
 * 
 * Returns:
 * 		// none
 * 
***/
void Snake::growAtFront(Position newPosition)
{
    // Create a new node at the front of the snake and update the head
    SnakeNode* newNode = new SnakeNode(newPosition);
    newNode->next = head;
    head = newNode;
}


/*** 
 * PLEASE UPDATE THIS METHOD
 * 
 * When snake slide to a newPosition,
 *  if tail->next == nullptr: // snake has only one node
 *      // tail->position is assigned by new position.
 *  else:
 *      SnakeNode *oldTailNode = tail;
 *      //cut the old tail off the snake
 *      tail = tail->next;
 *		oldTailNode->next = nullptr;
 *      // move it to the head of the snake
 *      oldTailNode position = newPosition;
 *  	head->next = oldTailNode;
 * Args:
 * 		pos (newPosition): head of snake grow at new position
 * 
 * Returns:
 * 		// none
 * 
***/

void Snake::slideTo(Position newPosition)
{
    if (tail->next == nullptr) {
        // If the snake has only one node, update its position
        tail->position = newPosition;
    }
    else {
        // Otherwise, remove the tail node and move it to the head
        SnakeNode* oldTailNode = tail;
        tail = tail->next;
        oldTailNode->next = nullptr;
        oldTailNode->position = newPosition;
        head->next = oldTailNode;
        head = oldTailNode;
    }
}

/*** 
 * PLEASE UPDATE THIS METHOD
 * 
 * When snake eat a Cherry,
 *  // if snake eat cherry, number of cherries will increase one
 * Args:
 * 		// none
 * 
 * Returns:
 * 		// none
 * 
***/
void Snake::eatCherry()
{
    cherry++;
}

/*** 
 * PLEASE UPDATE THIS METHOD
 * 
 * When snake move in a direction,
 *  1. Create a newPosition and move:
 *      Position newPosition = head->position.move(direction);
 *  2. Using snakeMoveTo method to update game with newPosition
 *      game.snakeMoveTo(newPosition);
 *  3. 
 *      If gameOver, return ; 
 *          return;
 *      elif cherry > 0:
 *          // If cherry > 0, cherry descrease one and growAtFront() with newPosition
 *          Note: Call to funtion growAtFront()
 *      else:
 *          // SlideTo() newPosition. 
 *          Note: Call to function SlideTo()
 *
 * Args:
 * 		pos (newPosition): head of snake grow at new position
 * 
 * Returns:
 * 		// none
 * 
***/

void Snake::move(Direction direction)
{
    // Create a new position based on the current head position and the direction
    Position newPosition = head->position.move(direction);

    // Move the snake to the new position
    game.snakeMoveTo(newPosition);

    // Check if the game is over
    if (game.isGameOver()) {
        return;
    }

    if (cherry > 0) {
        // If there are cherries, decrease cherry count and grow the snake
        cherry--;
        growAtFront(newPosition);
    }
    else {
        // Otherwise, slide the snake to the new position
        slideTo(newPosition);
    }

}

// DO NOT CHANGE METHOD
int Snake::getNumCherry(){
    return cherry;
}

// DO NOT CHANGE METHOD
SnakeNode* Snake::getHead(){
    return head;
}

// DO NOT CHANGE METHOD
SnakeNode* Snake::getTail(){
    return tail;
}
