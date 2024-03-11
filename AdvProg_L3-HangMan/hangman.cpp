if (ch == word[i])
{
    secretWord[i] = ch;
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
void updateEnteredChars(const char ch, string& chars) {
    // TODO: append the character ch is in end of the text chars
    chars.push_back(ch);
    // Thêm một dấu cách vào cuối chuỗi chars
    chars.push_back(' ');
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess) {
    // TODO: increase the value of incorrectGuess by 1
    incorrectGuess++;
}

/***
    Args:
        ch (char): a character that player enter to console
        word (string): answer word that play needs to guess
        secretWord (string): answer word in hidden form
        correctChars (string): a string that stores correct inputs of player
        incorrectGuess (int): a number that stores the number of player's wrong guess
        incorrectChars (string): a string that stores incorrect inputs of player
    Returns:
        void
***/
void processData(const char ch, const string& word,
    string& secretWord,
    string& correctChars,
    int& incorrectGuess, string& incorrectChars)
{
    /*** TODO
        If ch in word:
            update secretWord: call updateSecretWord() function
            update correctChars: call updateEnteredChars() function
        else:
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
    for (int i = 0; i < word.size(); i++)
    {
        if (ch == word[i])
        {
            updateSecretWord(secretWord, ch, word);
            updateEnteredChars(ch, correctChars);
            return;
        }
    }
    updateIncorrectGuess(incorrectGuess);
    updateEnteredChars(ch, incorrectChars);

}