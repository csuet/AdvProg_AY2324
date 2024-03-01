#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Position.h"

enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_OVER = 8 | GAME_STOP,
};

enum CellType {
    CELL_EMPTY = 0, // empty cell
    CELL_SNAKE,  // cell contains snake body
    CELL_CHERRY, // cell contains cherry
    CELL_OFF_BOARD // cell out of play screen. If snake moves to there, game over
};

class Game
{
    std::vector< std::vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score;
    std::queue<Direction> inputQueue;
    Direction currentDirection;
    Position cherryPosition;
public:
	const int width;
	const int height;
	
    Game(int _width, int _height);
    ~Game();

    bool isGameRunning() const { return status == GAME_RUNNING; }
    bool isGameOver() const { return status == GAME_OVER; }
    void processUserInput(Direction direction);
    void nextStep();
    const std::vector< std::vector<CellType> >& getSquares() const { return squares; }
    CellType getCellType(Position p) const;
    void setGameStatus(GameStatus status);

    std::vector<Position> getSnakePositions() const;
    Position getCherryPosition() const { return cherryPosition; }
    Direction getCurrentDirection() const { return currentDirection; }
    int getScore() const { return score; }
    bool canChange(Direction current, Direction next) const;    
    
    void snakeMoveTo(Position position);
    void snakeLeave(Position position);

    
    GameStatus getGameStatus();

    int getWidth();
    int getHeight();

    void setCellType(Position pos, CellType cellType);
    Snake getSnake();
	void addCherry();  
	
};

#endif // GAMEGROUND_H
