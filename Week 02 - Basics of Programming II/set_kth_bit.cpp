#include <bits/stdc++.h>
using namespace std;
//set bit means 1

int setKthBit(int n, int k) {
    // int mask = 1 << k;
    // int ans = n | mask;
    // return ans;
    int ans = n | (1<<k);
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int ans = setKthBit(n, k);
    cout << ans << endl;
    return 0;
}