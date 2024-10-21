#include <bits/stdc++.h>
using namespace std;

int convertToMin(string& time) {
    int hr = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return 60 * hr + min;
}

int findMinDifference(vector<string>& timePoints) {
    vector<int> mins;
    for(auto time: timePoints) {
        mins.push_back(convertToMin(time));
    }
    sort(mins.begin(), mins.end());
    int ans = INT_MAX; //? stores minimum difference
    for(int i = 0; i<mins.size()-1; i++) {
        ans = min(ans, mins[i+1] - mins[i]);
    }
    // last diff
    int lastDiff = mins[0] + 1440 - mins[mins.size()-1]; //! this condition is important
    ans = min(ans, lastDiff);
    return ans;
}

int main() {
    return 0;
}