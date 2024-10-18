#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 1, j = 0;
    // 2 pointers approach
    while (i < nums.size()){
        if (nums[i] == nums[j]) {
            i++;
        }
        else {
            nums[++j] = nums[i++];
            // j++;
            // nums[j] = nums[i];
            // i++;
        }
    }
    return j+1;
}

int main() {
    return 0;
}