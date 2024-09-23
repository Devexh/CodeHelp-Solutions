#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    int ans = 0;
    bool isNegative = false;

    if (x <= INT_MIN) { //main condition, equal to sign is must otherwise it will fail in the INT_MAX condition
        return 0;
    }

    if (x < 0){
        isNegative = true;
        x = -x;
    }

    while(x>0){
        if (x > INT_MAX/10) {
            return 0;
        }

        int digit = x % 10;
        ans = (ans*10)+ digit;
        x = x/10;
    }
    return isNegative ? -ans : ans;
}

int main() {
    int n;
    cin >> n;
    int rev = reverse(n);
    cout << "Reverse of " << n << " is " << rev << endl;
    return 0;
}