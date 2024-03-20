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
    srand(time(NULL));
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
    cout << endl << "Enter your guess: ";
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

    return answer;
}

void printAnswer(int guess, int secretNumber)
{
    if (guess > secretNumber) {
        cout << "Your number is too big." << endl;
    } else if (guess < secretNumber) {
        cout << "Your number is too small." << endl;
    } else {
        cout << "Congratulation! You win." << endl;
    }
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong

    return true;
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

    return isContinued;
}

int tinhDiem(int thua)
{
    return (10000 - 2 * (100 - thua));
}

bool choiLai()
{
    char luaChon;
    cout << "Ban co muon choi lai khong? (y/n): ";
    cin >> luaChon;
    return (luaChon == 'y');
}

void playGuessIt() {
    int guess, secretNumber, thua, diemTong = 0;
    bool choiNua;
    do
    {
        secretNumber = generateRandomNumber();
        thua = 0;
        do
        {
            guess = getPlayerGuess();
            printAnswer(guess, secretNumber);
            thua++;
        }while(guess != secretNumber);
        int diemVong = tinhDiem(thua);
        diemTong += diemVong;
        cout << "Diem cua ban cho vong nay: " << diemVong << endl;
        cout << "Tong diem: " << diemTong << endl;
        choiNua = choiLai();
    }while(choiNua);
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
