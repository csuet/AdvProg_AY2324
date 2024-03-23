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
    //Write your code here
    for(auto i: vocabulary)
    {
        if(i.size() == wordLen) answer.push_back(i);
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
{
    char answer;
    //Write your code here
    int it = 0;
    for(auto i: selectedChars)
    {
        int x = i - 'a';
        if(x!=it) break;
    }
    answer = char('a'+it);
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
    //Write your code here
    for(auto i: candidateWords)
    {
        for(auto j: i)
        {
            answer[j]++;
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

char findMostFrequentChar( map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int best = 0;
    //Write your code here
    for(char i: selectedChars)
    {
        if(occurrences[i]> best)
        {
            best = occurrences[i];
            answer = i;
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
    char answer;
    //Write your code here
    int best = 0;
    for(char x='a'; x<='z'; ++x)
    {
        if(selectedChars.count(x)==0)
        {
            int dem = 0;
            for(auto i: candidateWords)
            {
                for(auto j: i)
                {
                    if(j == x)
                    {
                        dem++;
                        //break;
                    }
                }
            }
            if(dem > best)
            {
                best = dem;
                answer = x;
            }
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
{
    bool answer = 0;
    //Write your code here
    for(int i= 0; i<(int)mask.size(); ++i)
    {
        if(mask[i] == ch) answer = 1;
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
{
     bool answer=1;
    //Write your code here
    for(int i= 0; i<(int)mask.size(); ++i)
    {
        if(!(mask[i]>='a'&&mask[i]<='z')) answer = 0;
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
{
    bool answer = 1;
    //Write your code here
    for(int i= 0; i<(int)mask.size(); ++i)
    {
        if(mask[i]<'a' || mask[i]>'z') continue;
        if(mask[i] != word[i]) answer = 0;
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
    //Write your code here
    for(auto i: words)
    {
        if(wordConformToMask(i, mask, ch)) answer.push_back(i);
    }
    return answer;
}


//
//int main()
//{   string fileNameCandidateWords, fileNameSelectedChars, fileNameNextChar;
//    fileNameCandidateWords = "test_data/find_best_char/candidate_words/7.txt";
//    fileNameSelectedChars = "test_data/find_best_char/selected_chars/7.txt";
//    fileNameNextChar = "test_data/find_best_char/next_char/7.txt";
//
//    ifstream fileCandidateWords(fileNameCandidateWords);
//        ifstream fileSelectedChars(fileNameSelectedChars);
//        ifstream fileNextChar(fileNameNextChar);
//        vector<string> candidateWords;
//        set<char> selectedChars;
//        char nextChar;
//
//        string tmpWord;
//        char tmpChar;
//
//        while(getline(fileCandidateWords, tmpWord)){
//            candidateWords.push_back(tmpWord);
//        }
//
//        while(fileSelectedChars >> tmpChar){
//            selectedChars.insert(tmpChar);
//        }
//
//        fileNextChar >> nextChar;
//
//        fileCandidateWords.close();
//        fileSelectedChars.close();
//        fileNextChar.close();
//        //cout<<1;
//        cout<<findBestChar(candidateWords, selectedChars);
//
//}
