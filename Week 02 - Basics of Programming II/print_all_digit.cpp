#include <bits/stdc++.h>
using namespace std;

void printAllDigits(int n) {
        while (n) {
            int onesPlaceDigit = n % 10;
            cout << "Digit: " << onesPlaceDigit << endl;
            n /= 10;
        }
}

int main() {
    int n;
    cout << "Enter number to see all digits" << endl;
    cin >> n;
    printAllDigits(n);
    return 0;
}