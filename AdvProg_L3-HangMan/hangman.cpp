#include <iostream>
#include "hangman.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::ifstream;
using std::string;
using std::vector;

int generateRandomNumber(const int min, const int max)
{

    int number = rand() % (max - min + 1) + min;
    return number;

}

vector<string> readWordListFromFile(const string &filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile(filePath);
    if (!wordFile.is_open())
    {
        throw domain_error("Unable to open file");
    }



                               
                                // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
                                // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        std::cout << word << '\n';

    }
    
    wordFile.close();

    return wordList;
}

bool isCharInWord(const char ch, const string &word)
{

    // TODO: return true if ch is in word else return false
    for ( char x: word)
    {
        if(ch==x) return true;

    }
    return false;
}

string chooseWordFromList(const vector<string> &wordList, int index)
{

    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;
    answer= wordList[index];
    for (int i=0;i<sizeof(answer) ; i++)
    {
        if(answer[i]>='A' && answer[i]<='Z') answer[i]+= 32;
    }
    return answer;
}

string generateHiddenCharacters(string answerWord)
{
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"

    string secretWord;
    for (char x: answerWord)secretWord+='-';

    return secretWord;
}

char getInputCharacter()
{
    char ch;
    cin >> ch;
    return tolower(ch);
}

void updateSecretWord(string &secretWord, const char ch, const string &word)
{

    // TODO: Update the secret word if the character ch is in the answer word.
    if(isCharInWord(ch,word))
    {
        for (int i=0;i<sizeof(word); i++)
        {
            if(word[i]==ch) secretWord[i]=ch;
        }
    }
}

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    

    chars.push_back(ch);
    chars.push_back(' ');
}


/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: increase the value of incorrectGuess by 1

}

void processData(const char ch, const string &word,
                 string &secretWord,
                 string &correctChars,
                 int &incorrectGuess, string &incorrectChars)
{

    /*** TODO
        If ch in word:
            update secretWord: call updateSecretWord() function
            update correctChars: call updateEnteredChars() function
        else:
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
   if(isCharInWord(ch,word)) 
   {
    updateSecretWord(secretWord,ch,word);
    updateEnteredChars(ch,correctChars);
   }
   else{
    updateIncorrectGuess(incorrectGuess);
    updateEnteredChars(ch,incorrectChars);

   }

}
