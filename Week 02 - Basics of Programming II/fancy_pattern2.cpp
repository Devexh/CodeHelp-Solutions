#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 1;
    //growing phase
    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            cout << c << " ";
            c++;
            if (col < row) {
                cout << "* ";
            }
        }
        cout << endl;
    }
    //shrinking phase
    int start = c - n;
    for (int row = 0; row < n; row++) {
        int k = start;
        for (int col = 0; col <= n-row-1; col++) {
            cout << k << " ";
            k++;
            if (col < n-row-1) {
                cout << "* ";
            }
        }
        start -= n-row-1;
        cout << endl;
    }
    return 0;
}