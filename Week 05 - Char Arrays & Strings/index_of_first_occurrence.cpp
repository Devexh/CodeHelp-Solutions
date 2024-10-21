#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n-m; i++) {
        for (int j = 0;j < m;j++) {
            if (needle[j] != haystack[i+j]) {
                break;
            }
            if (j == m-1) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    return 0;
}