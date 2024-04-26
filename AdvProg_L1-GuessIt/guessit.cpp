#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"
using namespace std;

int generateRandomNumber() {
    int randnum = rand() % 100 + 1;
    return randnum;
}

int getPlayerGuess() {
    int guess;
    cin >> guess;
    return guess;
}

string getAnswer(int number, int randomNumber) {
    string answer;
    if (number > randomNumber) {
        answer= "Your number is higher.";
    } else if (number < randomNumber) {
        answer=  "Your number is lower.";
    } else {
       answer=  "Congratulations! You win.";
    }
    return answer;
}

bool checkSuccess(string answer) {
    if(answer == "Congratulations! You win.")
    {
        return true;
    }
    return false;
}

bool checkContinuePlaying(char isContinued) {
    if( isContinued == 'y' || isContinued == 'Y')
    {
        return true;
    }
    return false;
}

char getPlayerOpinion() {
    char isContinued;
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

int main() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
