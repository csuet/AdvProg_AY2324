# Project: Snake Game

### You are required to implement several methods of `Game.cpp` and `Snake.cpp`. They could be done via the instructions as follows:

* Step 1: Fork this repo to your own account
* Step 2: Clone the forked repo to your local via the command: `git clone https://github.com/[YOUR_USERNAME]/snake.git`
* Step 3: Update the following methods:
    * In `Game.cpp`:
        
        * `snakeMoveTo(Position pos)`
        * `snakeLeave(Position position)`
        * `processUserInput(Direction direction)`
        * `canChange(Direction current, Direction next)`
        * `nextStep()`
        * `addCherry()`
        * `setCellType(Position pos, CellType cellType)`

    * In `Snake.cpp`:
        * `Destructor Snake`
        * `growAtFront(Position newPosition)`
        * `slideTo(Position newPosition)`
        * `eatCherry()`
        * `move(Direction direction)`

* Step 4: Commit & push the modified file using the command: `git commit -m "[Insert_your_own_message]" & git push origin main`
* Step 5: Create a pull request:
    * In the tab "Pull requests", click on "New pull request"
    * Set the pull request's title with the format as: [Your_student_ID]_[Your_full_name]
    * Click on "Create pull request" to submit 

* Step 6: Step 6: Check the automated testing workflow on your modified code using Github Actions. Beside that, you also can see the main.cpp, where there are several drawing beautiful objects's code, and try to build and run this code. Hope you enjoy the lesson.

**Note**
* Except `Game.cpp`, `Snake.cpp`, DO NOT change any file.
* You may optionally wish to create your own `Makefile` to prevent error in testing phase with your local machine. But DO NOT commit and push the change to Github.



