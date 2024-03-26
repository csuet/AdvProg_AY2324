#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "guessit.h"

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    srand(time(0));
    return rand() % 100 + 1;
}


/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
     int guess;
    do {
        cout << "Enter your guess (1-100): ";
        if (!(cin >> guess)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else if (guess < 1 || guess > 100) {
            cout << "Guess must be between 1 and 100." << endl;
        }
    } while (guess < 1 || guess > 100);
    return guess;
    }


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    /*** 
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if (number > randomNumber) {
        answer = "Your number is higher.";
    } else if (number < randomNumber) {
        answer = "Your number is lower.";
    } else {
        answer = "Congratulation! You win.";
    }
    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    return answer == "Congratulation! You win.";
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    isContinued = tolower(isContinued);
    if (isContinued == 'y') {
        result = true;
    }
    return result;
}


/***
    Args:
        
    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    do {
        cout << "Do you want to play again (y/n)? ";
        cin >> isContinued;
        isContinued = tolower(isContinued);
    } while (isContinued != 'y' && isContinued != 'n');

    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}