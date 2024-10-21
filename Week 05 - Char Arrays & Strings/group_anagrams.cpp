#include <bits/stdc++.h>
using namespace std;

//! Method 1
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;

    for (auto str: strs) {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}

//! Method 2
std::array<int, 256> hashs(string s) {
    std::array<int, 256> hashs = {0};
    for (int i = 0; i < s.size(); i++) {
        hashs[s[i]]++;
    }
    return hashs;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<std::array<int, 256>, vector<string>> mp;

    for (auto str: strs) {
        mp[hashs(str)].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}

int main() {
    return 0;
}