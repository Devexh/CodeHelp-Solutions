#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++) {
        int c = 1;
        for (int col = 1; col <= row; col++) {
            cout << c << " ";
            c = c*(row-col)/(col); //binary coefficient formula
        }
        cout << endl;
    }
    return 0;
}