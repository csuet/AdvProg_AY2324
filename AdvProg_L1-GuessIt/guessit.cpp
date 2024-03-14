#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    return rand() % 100 + 1;
}


/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int PlayerGuess;
	cout << "Enter Your Guess (1...100) : ";
	cin >> PlayerGuess;
	return PlayerGuess;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {  
    string answer;
    if (number > randomNumber) {
        answer = "Your Number is too big";
    } else if (number < randomNumber) {
        answer = "Your Number is too small";
    } else {
        answer = "Congratulation! You Win.";
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
    bool result = true;
    if (answer != "Congratulation! You Win.") {
        result = false;
    }
    return result;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = true;
    if (isContinued == '0') {
        result = false;
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
    cout << "Do you want to play again ? (1 or 0)" << endl;
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
