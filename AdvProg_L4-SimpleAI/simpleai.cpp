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
**
wordLen(int) : Độ dài mong muốn của từ đầu vào
từ vựng(vector<string>) : Từ vựng
Trả về :
câu trả lời(vector<string>) : Một tập hợp hoặc từ trong từ vựng trong đó số lượng ký tự bằng wordLen*/
// lọc danh sách từ vựng để lây từ có độ dài chính xác
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for (const string& word : vocabulary) {
        if (word.length() == wordLen) {
            answer.push_back(word);
        }
    }
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/
/***
     Lập luận:
         selectedChars (set<char>): Các ký tự được dự đoán
     Trả về:
         câu trả lời (char): Ký tự tiếp theo của từ được cung cấp không có trong từ vựng
***/
// tìm kí tự chưa xuất hiện trong selectedChars để đoán
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars) {
    char answer;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (selectedChars.find(ch) == selectedChars.end()) {
            answer = ch;
        }
    }
    // Nếu tất cả các ký tự đều có trong selectedChars, thì không có ký tự nào để trả về
    return answer;
}


/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/
// đếm số lần xuất hiện của từng ký tự trong candidateWords. Một bản đồ được sử dụng để lưu trữ tần số ký tự.
map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    
    map<char, int> answer;
    for (const string& word : candidateWords) {
        for (char ch : word) {
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
/***
     Lập luận:
         lần xuất hiện (map<char, int>): Bản đồ đếm số lần xuất hiện của ký tự trong tập hợp các từ ứng cử viên
         selectedChars (set<char>): Các ký tự được dự đoán
     Trả về:
         câu trả lời (char): Ký tự thường xuyên nhất
***/
// tim ki tu co tan suat cao nhat trong ban do occurrences ma chua co trong selectedChars
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/
/***
     Lập luận:
         ứng cử viênWords (vector<string>): Các từ ứng viên cho chuỗi hiện tại
         selectedChars (set<char>): Các ký tự được dự đoán
     Trả về:
         câu trả lời (char): Ký tự phù hợp nhất để dự đoán
***/
// tim ki tu phu hop nhat de du doan tiep theo dua tren candidateWords va selectedChars
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    return answer;
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


// xac dinh xem ki tu du doan co dung hay khong dua tren mask
bool isCorrectChar(char ch, const string& mask)
{
    bool answer;
    for (char c : mask)
    {
        if (ch == c)
            answer = true;
        else
            answer = false;
   }
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

/***
     Lập luận:
         mặt nạ (chuỗi): Mặt nạ phản hồi của người chơi
     Trả về:
         câu trả lời (bool): trả về Sai nếu mặt nạ được cung cấp không phải là toàn bộ từ, Ngược lại là Đúng
         (Ví dụ: -False: g__d
                   -Đúng: tốt)
***/
// xac dinh xem mask co phai 1 tu hoan chinh hay khong
bool isWholeWord(const string& mask)
{
     bool answer=true;
    //Write your code here
     for (char c : mask)
     {
         if (c == '_') {
             answer = false;
         }
     }
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
//  kiểm tra xem từ đã cho có khớp với mặt nạ được cung cấp và ký tự được dự đoán hay không.g
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer;
    //Write your code here
    if (word.size() != mask.size()) {
        answer=false; // Nếu độ dài của từ và mặt nạ không khớp, trả về false
    }

    for (size_t i = 0; i < word.size(); i++) {
        // Nếu ký tự trong mask là ký tự dự đoán hoặc dấu '_', tiếp tục kiểm tra
        if (mask[i] == ch || mask[i] == '_') {
            continue;
        }

        // Nếu ký tự trong mask khác ký tự trong word, trả về false
        if (mask[i] != word[i]) {
            answwer= false;
        }
        else {
            answer = true;
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
// lọc danh sách các từ đề cử dựa trên mặt nạ được cung cấp và ký tự được dự đoán.
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for (const string& word : words) {
        if (wordConformToMask(word, mask, ch)) {
            answer.push_back(word);
        }
    }
    return answer;
}