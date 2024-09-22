#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // if row == 0 and n-1 then print all stars
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++){
            if (row == 0 || row == n-1 || col == 0 || col == n-1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}