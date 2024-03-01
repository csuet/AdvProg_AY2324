# Lesson 3: HangMan:
This is the third lesson of the Advanced Programming course with the following objectives:
* i) Understand about the hangman game source code structure.
* ii) Learn about the automated testing with github Actions.

You are required to implement several functions of HangMan game. They could be done via the instructions as follows:

* Step 1: Fork this repo to your own account
* Step 2: Clone the forked repo to your local via the command: git clone https://github.com/[YOUR_USERNAME]/AdvProg_L3-HangMan.git
* Step 3: Modify the "hangman.cpp" file to complete the requirement. Specifically, there are 8 functions that you have to implement namely:
  - int generateRandomNumber(const int min, const int max);
  - bool isCharInWord(const char ch, const string& word);
  - string generateHiddenCharacters(string secretWord)
  - string chooseWordFromList(const vector<string>& wordList, int index);
  - void updateSecretWord(string& secretWord, const char ch, const string& word);
  - void updateEnteredChars(const char ch, string& chars);
  - void updateIncorrectGuess(int& incorrectGuess);
  - void processData(const char ch, const string& word, string& secretWord, string& correctChars, int& incorrectGuess, string& incorrectChars);
* Step 4: Commit & push the modified file using the command: git commit -m "[Insert_your_own_message]" & git push origin main
* Step 5: Create a pull request:
In the tab "Pull requests", click on "New pull request"
Set the pull request's title with the format as: [Your_student_ID]_[Your_full_name]
Click on "Create pull request" to submit
* Step 6: Check the automated testing workflow on your modified code using Github Actions.
Hope you enjoy the lesson.