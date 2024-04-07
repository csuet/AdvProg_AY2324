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
{// hàm này dùng để lọc các từ có độ dài bằng wordLen có trong vector vocabulary
    vector<string> answer;
    //Write your code here
    for(int i=0;i<vocabulary.size();i++){
            int x=vocabulary[i].size();
            if(x==wordLen){
                answer.push_back(vocabulary[i]);
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

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{// hàm dự đoán ký tự tiếp theo nếu từ hiện tại không có trong từ điển
    char answer;
    //Write your code here
    if (selectedChars.empty()) {
        answer = 'b';
    } else {
        answer = *selectedChars.begin();
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
{// đếm số lần xuất hiện của mỗi ký tự của các từ trong vector candidateWords;
    map<char, int> answer;
    //Write your code here
    for(size_t i=0;i<candidateWords.size();i++){
            int x=candidateWords[i].size();
            string word=candidateWords[i];
        for(size_t j=0;j<x;j++){
                answer[word[j]]++;
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
{// tìm ra ký tự xuất hiện nhiều nhất trong map mà không có trong selectedChars
    char answer;
    //Write your code here
    int cnt;
    for(auto it=occurrences.begin();it!=occurrences.end();it++){
            char c = it->first;
    if(selectedChars.find(c)==selectedChars.end()&& it->second>cnt){
        answer=c;
        cnt=it->second;
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
{//hàm tìm ra ký tự tốt nhất để dự đoán dựa trên các từ đã có candidateWord và các ký tự đã đoán selectedChars
    char answer;
    map<char,int> mp;
    //Write your code here
    for(size_t i=0;i<candidateWords.size();i++){
        string s=candidateWords[i];
        for(size_t j=0;j<s.size();j++){
                mp[s[j]]++;
        }
    }
    int cnt=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        char c=it->first;
        if(selectedChars.find(c)==selectedChars.end()&&it->second>cnt){
                answer=c;
                cnt=it->second;
        }
    }
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

bool isCorrectChar(char ch, const string& mask)
{// kiểm tra xem ký tự ch có trong mask ko
    bool answer=true;
    //Write your code here
   if(mask.find(ch)==string::npos){
        answer=false;
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
bool isWholeWord(const string& mask)
{// kiểm tra mask có phải một từ hoàn chỉnh hay không
     bool answer=true;
    //Write your code here
    for(size_t i=0;i<mask.size();i++){
        if(mask[i]=='_'){
            answer=false;
            break;
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
bool wordConformToMask(const string& word, const string& mask, char ch)
{// so sánh word và mask có giống nhau không
    bool answer=true;
    //Write your code here
    if (mask.size() != word.size()) {
        answer = false;
    } else {
        for (size_t i = 0; i < mask.size(); i++) {
            if (mask[i] != '-' && mask[i] != word[i] && ch != word[i]) {
                answer = false;
                break;
            }
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
{// hàm này lấy ra các từ trong danh sách words nếu các từ đó = mask
    vector<string> answer;
    //Write your code here
    for (size_t i=0;i<words.size();i++) {
            string word=words[i];
        if (wordConformToMask(word, mask, ch)) {
            answer.push_back(word);
        }
    }
    return answer;
}
