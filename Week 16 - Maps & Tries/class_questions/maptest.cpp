#include <bits/stdc++.h>
using namespace std;

void countCharacters(unordered_map<char, int> &mapping, string str) {
    for (long long unsigned int i = 0; i < str.length(); i++) {
        char ch = str[i];
        mapping[ch]++;
    }
}

int main() {
    string str = "lovebabbar";
    unordered_map<char, int> mapping;
    countCharacters(mapping, str);

    for (auto i: mapping) {
        cout << i.first << "->" <<i.second << endl;
    }
    return 0;
}
