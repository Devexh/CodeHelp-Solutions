#include <bits/stdc++.h>
using namespace std;

// through bitwise solution we should remember that for even number LSB is 0 and for odd number it is 1
bool checkEvenMod(int n) {
    if (n%2 == 0) {
        return true;
    }
    else {
        return false;
    }
}
//Bitwise solution (it is faster)
bool checkEvenBitwise(int n) {
    if ((n&1) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    bool isEven = checkEvenBitwise(n);
    if (isEven) {
        cout << n << " is Even number.\n";
    }
    else {
        cout << n << " is Odd number.\n";
    }
    return 0;
}