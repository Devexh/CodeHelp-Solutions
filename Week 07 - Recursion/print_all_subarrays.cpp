#include <bits/stdc++.h>
using namespace std;
//* TC -> O(n^2); SC -> O(n)
void printSubArray_util(vector<int> &nums, int start, long long unsigned int end) { //? utility function for printSubArray
    // base case
    if (end == nums.size()) {
        return;
    }
    //one case solution
    for (long long unsigned int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    //Recursive Call
    printSubArray_util(nums, start, end+1);
}

void printSubArray(vector<int>& nums) {
    for (long long unsigned int start = 0; start < nums.size(); start++) {
        int end = start;
        printSubArray_util(nums, start, end);
    }
}

int main() {
    vector<int> nums{1,2,3,4,5};
    printSubArray(nums);
    return 0;
}
