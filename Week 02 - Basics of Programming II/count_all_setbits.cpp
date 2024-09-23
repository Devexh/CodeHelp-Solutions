#include <bits/stdc++.h>
using namespace std;

int countSetBit(int n) {
    int count = 0;
    while (n>0) {
        int bit = n % 2;
        if (bit == 1){
            count++;
        }
        n=n/2;
    }
    return count;
}
// by doing bitwise AND with 1 we'll get the LSB(Least Significant Bit) of the number
int countSetBitwise(int n) {
    int count = 0;
    while (n>0) {
        int bit = n & 1;
        if (bit == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int setBitCount = countSetBitwise(n);
    cout << setBitCount << endl;
    return 0;
}