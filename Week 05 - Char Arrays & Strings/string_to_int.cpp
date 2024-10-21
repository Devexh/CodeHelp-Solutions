#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int num = 0, i = 0, sign = 1; //+ve
    while (s[i] == ' ') {
        i++;
    }

    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = s[i] == '+' ? 1: -1;
        ++i;
    }
    
    while (i<s.size() && isdigit(s[i])) {
        if (num > INT_MAX/10 || (num = INT_MAX/10 && s[i] > '7')) { //! special condition to solve overflow issues
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        ++i;
    }
    return num*sign;
}

int main() {
    return 0;
}