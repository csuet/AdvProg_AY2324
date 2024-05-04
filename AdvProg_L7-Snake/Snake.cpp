#include "Snake.h"
#include "Game.h"
#include <iostream>

void Snake::growAtFront(Position newPosition)
{
    // head of snake grow at new position
    SnakeNode *newHead = new SnakeNode(newPosition, head);
    head = newHead;
}

void Snake::slideTo(Position newPosition)
{
    if (tail->next == nullptr) {
        // snake has only one node
        // tail->position is assigned by new position.
        tail->position = newPosition;
    } else {
        SnakeNode *oldTailNode = tail;
        // cut the old tail off the snake
        tail = tail->next;
        oldTailNode->next = nullptr;
        // move it to the head of the snake
        oldTailNode->position = newPosition;
        head->next = oldTailNode;
        head = oldTailNode;
    }
}

void Snake::eatCherry()
{
    cherry++;
}

void Snake::move(Direction direction)
{
    Position newPosition = head->position.move(direction);

    game.snakeMoveTo(newPosition);

    if (game.isGameOver())
        return;

    if (cherry > 0) {
        cherry--;
        growAtFront(newPosition);
    } else {
        game.snakeLeave(tail->position);
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
