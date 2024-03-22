#include<iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;



int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    int ran = rand()%100+1;
    return ran;
}


int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number

    cout<<"enter num: "<<endl;
    int n;
    cin>>n;
    return n;
}


 string getAnswer(int number, int randomNumber) {
   
    string answer;

    if(number>randomNumber){
        answer="Your number is higher.";
    }else if(number>randomNumber){
        answer="Your number is lower.";
    }else{
        answer ="Congratulation! You win.";
    }
    return answer;
}


bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong

    if(answer =="Congratulation! You win."){

    return true;
    }else {
        return false;
    }
}



bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;

    
    return result;
}

char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;

    cin>>isContinued;
    return isContinued;
}
