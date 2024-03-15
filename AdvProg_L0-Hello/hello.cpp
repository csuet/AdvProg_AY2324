#include <iostream>
#include <vector>

using namespace std;

void generateWords(int N, int K, string word, vector<bool>& usedChars) {
    if (K == 0) {
        cout << word << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!usedChars[i]) {
            usedChars[i] = true;
            generateWords(N, K - 1, word + char('a' + i), usedChars);
            usedChars[i] = false;
        }
    }
}

int main() {
    int N, K;
    cin >> N;
    cin >> K;

    if (N < K || N > 26 || K <= 0) {
        cout << "-1" << endl;
        return 0;
    }

    vector<bool> usedChars(N, false);
    string word = "";

    generateWords(N, K, word, usedChars);

    return 0;
}
