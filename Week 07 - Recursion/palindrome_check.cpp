#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s, int start, int end) { //? TC -> O(n); SC -> O(n)
    //base case
    if (start >= end) {
        return true;
    }
    //one case solution
    if (s[start] != s[end]) {
        return false;
    }

    return isPalindrome(s, start+1, end-1);
}

int main() {
    string s;
    cin >> s;
    cout << isPalindrome(s, 0, s.size()-1) << endl;
    return 0;
}