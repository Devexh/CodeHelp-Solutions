#include <bits/stdc++.h>
using namespace std;

int sortingMethod(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i == nums[i]) continue;
        else {
            return i;
        }
    }
    return nums.size();
}

//XOR method
int xorr(vector<int>& nums) {
    int ans = 0;
    //1. XOR all values of array
    for (int i = 0; i < nums.size(); ++i) {
        ans ^= nums[i];
    }

    //2. XOR all range items [0, n]
    int n = nums.size();
    for (int i = 0; i <= n; i++) {
        ans ^= i;
    }
    return ans;
}

int missingNumber(vector<int>& nums) {
    return xorr(nums);
}

int main() {
    return 0;
}