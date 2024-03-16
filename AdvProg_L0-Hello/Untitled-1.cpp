#include <bits/stdc++.h>

void print(char arr[], int n, int k, int start, std::string s) {
    if(k == 0) {std::cout << s << std::endl; return;}
    int temp = k;
    int i = start;
    if(i >= n) i = 0;
    s+=arr[i];
    ++i;
    while(k--) print(arr, n, k-1, i,s);
}

int main() {
    int n, k; std::cin >> n >> k;
    std::string s;
    for(int i = 0; i < n; ++i) s += 'a' + i;
    print(arr, n, k, 0,s);
    return 0;
}