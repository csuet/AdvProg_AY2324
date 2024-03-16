#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"
#include <bits/stdc++.h>

using namespace std;


/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    int n = rand() % (100 - 1 + 1) + 1;
    return n;
}


/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int guess;
    cout << endl << "Enter your guess (1..100): ";
    cin >> guess;
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
    if (number > randomNumber) answer = "Your number is higher.";
    if (number < randomNumber) answer = "Your number is lower.";
    if (number == randomNumber) answer = "Congratulation! You win.";

    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    if(answer == "Congratulation! You win.") return 1;

    return 0;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    if(isContinued == 'y') return 1;
    return 0;
}


/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cout << "Do you want to play more? :";
    cin >> isContinued;
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
