#include <bits/stdc++.h>
using namespace std;

static bool mycomp(string a, string b) { //* Custom Comparator
    string t1 = a+b;
    string t2 = b+a;
    return t1 > t2;
}

string largestNumber(vector<int>& nums) {
    vector<string> snums;
    for (auto n: nums) {
        snums.push_back(to_string(n));
    }
    
    sort(snums.begin(), snums.end(), mycomp); //! Lexicographically sorting
    if (snums[0] == "0") return "0"; //? test case for {0,0,0,0}

    string ans = "";
    for (auto str: snums) {
        ans += str;
    }
    return ans;
}

int main() {
    return 0;
}