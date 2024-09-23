#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = n;
    for (int row = 0; row < n; row++) {
        int c = 1;
        for (int col = 0; col < k; col++) {
            if (col < n-row-1){
                cout << "  ";
            }
            else if(col<=n-1) {
                cout << c << " ";
                c++;
            }
            else if (col == n) { // since the value of c has been incremented by 2 due to c++
                c -=2;
                cout << c << " ";
                c--; //main part
            }
            else {
                cout << c << " ";
                c--;
            }
        }
        k++;
        cout << endl;
    }
    return 0;
}