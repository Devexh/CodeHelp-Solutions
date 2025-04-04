#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end) { //! O(n^3) can be resolved into O(n^2) with DP Solution
    while (start<end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++, end--;
    }
    return true;
}

string longestPalindrome(string s) {
    string ans = "";

    for (int i = 0; i<s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                string t = s.substr(i, j-i+1);
                ans = t.size() > ans.size() ? t: ans;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}