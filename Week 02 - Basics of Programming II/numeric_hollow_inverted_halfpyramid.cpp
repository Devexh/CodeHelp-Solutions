#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int col = row+1; col<=n; col++) {
            if (col == n || col == row + 1 || row == 0) {
                cout << col << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}