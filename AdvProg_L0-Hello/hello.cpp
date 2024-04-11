#include <iostream>
#include <vector>

using namespace std;

std::vector<vector<int>> generateMagicSquare(int n) {
    std::vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        j++; i--;
    }

    return magicSquare;
}

void printMiddleRow(const vector<vector<int>>& magicSquare) {
    int n = magicSquare.size();
    for (const auto& num : magicSquare[n/2]) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the order of magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "The order of magic square must be an odd number.\n";
        return 1;
    }

    vector<vector<int>> magicSquare = generateMagicSquare(n);
    printMiddleRow(magicSquare);

    return 0;
}