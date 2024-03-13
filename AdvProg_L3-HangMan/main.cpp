#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>
#include <algorithm>

#include "hangman.h"
#include "draw.h"

int main()
{
    srand((int)time(0));

    string vocabularyFile = "Ogden_Picturable_200.txt";
    //string vocabularyFile = "data/ErrorOpenFileTest.txt";
    //string vocabularyFile = "data/EmptyTest.txt";
    vector<string> wordList;

    do{
        try{
            wordList = readWordListFromFile(vocabularyFile);
        } catch(std::exception& e){
            cout << endl << "Loi: " << e.what() << " trong doc tu trong: " << vocabularyFile << endl;
            return 1;
        }

        int index = generateRandomNumber(0, wordList.size() - 1);
        string word = chooseWordFromList(wordList, index);

        if(word.empty())
        {
            cout << "Loi: khong the chon tu bat ky" << endl;
            return 1;
        }

        string secretWord = generateHiddenCharacters(word);
        int incorrectGuess = 0;
        string correctChars = "";
        string incorrectChars = "";

        do{
            char ch = getInputCharacter();
            processData(ch, word, secretWord, correctChars, incorrectGuess, incorrectChars);

            printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars);

            // Kiem tra trang thai cua tro choi (doan dung het hoac doan sai qua so lan cho phep)
            if(secretWord == word || incorrectGuess >= MAX_MISTAKES)
            {
                playAnimation(word, secretWord, correctChars, incorrectGuess, incorrectChars);
                break; // Ket thuc vong lap khi tro choi ket thuc
            }
        } while(true); // Vong lap vo han

        // Hien thi diem so va xac dinh xem nguoi choi muon choi tiep hay khong
        cout << "Ban co muon choi lai khong? (y/n): ";
        char choiLai;
        cin >> choiLai;

        if(tolower(choiLai) != 'y'){
            cout << "Game over!" << endl;
            break;
        }

    } while(true);
    return 0;
}
