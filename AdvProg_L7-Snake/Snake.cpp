#include "Snake.h"
#include "Game.h"
#include <iostream>

void Snake::growAtFront(Position newPosition)
{
    SnakeNode *newHead = new SnakeNode(newPosition, nullptr);
    head->next = newHead;
    head = newHead;
}

void Snake::slideTo(Position newPosition)
{
    if (tail->next == nullptr)
    {
        tail->position = newPosition;
    }
    else
    {
        SnakeNode *oldTailNode = tail;
        tail = tail->next;
        oldTailNode->next = nullptr;
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

    if (cherry > 0)
    {
        cherry--;
        growAtFront(newPosition);
    }
    else
    {
        game.snakeLeave(tail->position);
        slideTo(newPosition);
    }
}
