#include <bits/stdc++.h>
using namespace std;
//* TC -> O(mn) -> O(n/m*nm) = O(n^2); SC -> O(n/m)

void removeOccurrence(string &s, string &part) {
    int found = s.find(part);
    if (found != string::npos) {
        //part string has been located. Please remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found+part.size(), s.size());
        s = left_part + right_part;

        removeOccurrence(s, part);
    }
    else {
        //base case. All the occurrences of part has been removed from s.
        return;
    }
}

string removeOccurrences(string s, string part) {
    removeOccurrence(s, part);
    return s;
}

int main() {
    return 0;
}
