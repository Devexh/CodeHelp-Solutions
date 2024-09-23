#include <bits/stdc++.h>
using namespace std;

int createNumberUsingDigits(int numberOfDigits) {
    int num = 0;
    for (int i = 0; i < numberOfDigits; i++) {
        cout << "Enter Digit: ";
        int digit;
        cin >> digit;
        num = num*10 + digit;
    }
    return num;
}

int main() {
    int numberOfDigits;
    cin >> numberOfDigits;
    int num = createNumberUsingDigits(numberOfDigits);
    cout << "Number created by digits: " << num << endl;
    return 0;
}