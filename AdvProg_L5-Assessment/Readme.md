# Lesson 5 - Assessments:
This is a fifth lesson of Advanced Programing course with the following objectives:
* i) A collection of assessments to help you evaluate the performance of Guesser
* ii) Understand how to compare the performance between the Guessers.

You are required to implement several functions of Assessment. They could be done via the instructions as follows:
* Step 1: Fork this repo to your own account (Ignore if you did it before)
* Step 2: Clone the forked repo (Ignore if you did it before)
* Step 3: Modify the following functions in [assessment.cpp](assessment.cpp) to complete the requirement.:
  * `bool operator<(const MistakeByWord& m) const` in [assessment.h](assessment.h)
  * `void updateMask(std::string& mask, const char ch, const std::string& word);`
  * `int countMistakes(const std::string& word, HangmanGuesser& hmGuesser);`
  * `void getMistakeByWordList(std::vector<MistakeByWord>& mistakeList, std::vector<std::string>& unsolvableList, const std::vector<std::string> & testWords, HangmanGuesser& hmGuesser);`
* Step 4: Commit & push the modified file using the command: git commit -m "[Insert_your_own_message]" & git push origin master
* Step 5: Create a pull request:
In the tab "Pull requests", click on "New pull request"
Set the pull request's title with the format as: [Your_student_ID]_[Your_full_name]
Click on "Create pull request" to submit
* Step 6: Check the automated testing workflow on your modified code using Github Actions.
Hope you enjoy the lesson.