#include <bits/stdc++.h>
using namespace std;

void printPermutation(string &str, long long unsigned int index) {
    //base case
    if (index >= str.length()) {
        cout << str << " ";
        return;
    }

    for (long long unsigned int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        //recursion
        printPermutation(str, index+1);
        //! backtracking
        swap(str[index], str[j]);
    }
}

int main() {
    string str = "abc";
    int index = 0;
    printPermutation(str, index);

    return 0;
}