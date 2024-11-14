#include <bits/stdc++.h>
using namespace std;
//! STL function -> strrchr()

// void lastOccLTR(string& s, char x, int i, int& ans) {
//     *base case
//     if (i >= s.size()) {
//         return;
//     }
//     *one case solution
//     if (s[i] == x) {
//         ans = i;
//     }
//     *Recursive call
//     lastOccLTR(s, x, i+1, ans);
// }

void lastOccRTL(string& s, char x, int i, int& ans) {
    //base case
    if (i < 0) {
        return;
    }
    //one case solution
    if (s[i] == x) {
        ans = i;
        return;
    }
    //Recursive call
    lastOccRTL(s, x, i-1, ans);
}

int main() {
    string s;
    cin >> s;
    char x;
    cin >> x;
    int ans = -1;
    lastOccRTL(s, x, s.size()-1, ans);
    cout << ans << endl;
    return 0;
}