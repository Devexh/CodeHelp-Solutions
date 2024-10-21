#include <bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s)  { //? O(n)
    int l = 0, h = s.size()-1;
    while (l<h) {
        if (isalpha(s[l]) && isalpha(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if (!isalpha(s[l])) {
            l++;
        }
        else {
            h--;
        }
    }
    return s;
}

int main() {
    return 0;
}