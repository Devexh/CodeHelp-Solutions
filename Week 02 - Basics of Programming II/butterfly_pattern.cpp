#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int row = 0; row < 2*n; row++) {
        int cond = row < n ? row : n + (n-row-1); //important dry run conditions
        int space_count = row < n ? 2*(n-row-1) : row-cond-1;
        for (int col = 0; col < 2*n; col++) {
            if (col <= cond) {
                cout << "* ";
            }
            else if (space_count > 0) {
                cout << "  ";
                space_count--;
            }
            else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}