#include "simpleai.h"

int readMaxGuess()
{
    int maxGuess;
    cout << endl << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;
    
}

/***
    Args:
        wordLen (int): The desired length of input word
        vocabulary (vector<string>): The vocabulary
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for(int i = 0; i < vocabulary.size();i++) {
    if(wordLen==vocabulary[i].length())
        answer.push_back(vocabulary[i]);
}
    //Write your code here
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer; // Ký tự cần trả về

    char defaultChar = 'a'; // Chọn ký tự đầu tiên trong bảng chữ cái làm ký tự mặc định

    // Nếu không có ký tự nào được chọn trước đó, trả về ký tự mặc định
    if (selectedChars.empty()) {
        answer = defaultChar;
    } else {
        // Nếu có ít nhất một ký tự được chọn trước đó, hãy tìm ký tự tiếp theo trong bảng chữ cái
        // bằng cách lấy ký tự tiếp theo sau ký tự cuối cùng trong selectedChars
        char lastSelectedChar = *selectedChars.rbegin(); // Lấy ký tự cuối cùng trong selectedChars
        answer = lastSelectedChar + 1; // Ký tự tiếp theo sau ký tự cuối cùng
    }

    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/
map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;

    // Lặp qua từng từ trong vector candidateWords
    for (const string& word : candidateWords) {
        // Lặp qua từng ký tự trong từ hiện tại
        for (char ch : word) {
            // Tăng số lần xuất hiện của ký tự trong map
            answer[ch]++;
        }
    }

    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer; // Ký tự cần trả về

    int maxCount = 0; // Số lần xuất hiện lớn nhất

    // Lặp qua các cặp (ký tự, số lần xuất hiện) trong map occurrences
    for (const auto& pair : occurrences) {
        char ch = pair.first; // Ký tự
        int count = pair.second; // Số lần xuất hiện

        // Kiểm tra nếu ký tự chưa được chọn trước đó và có số lần xuất hiện lớn hơn maxCount
        if (selectedChars.find(ch) == selectedChars.end() && count > maxCount) {
            // Cập nhật ký tự và số lần xuất hiện lớn nhất
            answer = ch;
            maxCount = count;
        }
    }

    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    // Đếm số lần xuất hiện của từng ký tự trong tập hợp các từ ứng viên
    map<char, int> occurrences = countOccurrences(candidateWords);

    // Tìm ký tự xuất hiện nhiều nhất không được chọn trước đó
    char mostFrequentChar = findMostFrequentChar(occurrences, selectedChars);

    return mostFrequentChar;
}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

/***
    Args:
        ch (char): The predicted character by the AI
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/
bool isCorrectChar(char ch, const string& mask)
{
    // Kiểm tra xem ký tự đã được dự đoán có xuất hiện trong mask không
    bool answer = (mask.find(ch) != string::npos);
    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string& mask)
{
    // Kiểm tra xem mask có chứa ký tự '_' hay không
    bool answer = (mask.find('_') == string::npos);
    return answer;
}

/***
    This function should be used to support the filterWordsByMask function below
    Args:
        mask (string): The response mask by the player
        word (string): input word
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True: mask(-ood), char 'd'  vs word(good)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    // Kiểm tra xem từ word có phù hợp với mask và ký tự được dự đoán không
    bool answer = true;

    // Lặp qua từng ký tự của từ và mask
    for (int i = 0; i < word.size(); ++i) {
        // Nếu ký tự ở vị trí i trong mask là '_', tiếp tục kiểm tra ký tự tiếp theo
        if (mask[i] == '_') {
            continue;
        }

        // Nếu ký tự ở vị trí i trong mask không phù hợp với ký tự tương ứng trong từ word
        if (mask[i] != word[i] || (mask[i] == ch && word[i] != ch)) {
            answer = false;
            break;
        }
    }

    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfiy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;

    // Lặp qua từng từ trong vector words
    for (const string& word : words) {
        // Nếu từ đó phù hợp với mask và ký tự được dự đoán
        if (wordConformToMask(word, mask, ch)) {
            // Thêm từ vào vector kết quả
            answer.push_back(word);
        }
    }

    return answer;
}
