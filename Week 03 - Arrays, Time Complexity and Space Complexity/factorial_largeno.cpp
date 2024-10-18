#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n) {
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i<=n; i++) {
        for (int j = 0; j<ans.size(); j++) {
            int x = ans[j]*i + carry;
            ans[j] = x%10;
            carry = x/10;
        }
        while (carry) { //? if carry is also large then we have to use while loop
            ans.push_back(carry%10);
            carry /= 10;
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}