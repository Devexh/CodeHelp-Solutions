#include <bits/stdc++.h>
using namespace std;

//* 2 pair approach
int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int i = 0, j = 1;
    while (j < nums.size()) {
        int diff = nums[j] - nums[i];
        if (diff == k) {
            ans.insert({nums[i], nums[j]});
            ++i,++j; 
        }
        else if(diff > k) {
            i++;
        }
        else {
            j++;
        }
        if (i == j) j++;
    }
    return ans.size();
}

//* Binary Search Approach
int binarySearch(vector<int>& nums, int start, int x) { //* O(logn)
    int end = nums.size();
    while (start <= end) {
        int mid = (start+end)/2;
        if (nums[mid] == x) {
            return mid;
        }
        else if (x > nums[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int findPairs(vector<int>& nums, int k) { //* O(nLogn)
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(binarySearch(nums, i+1, nums[i]+k) != -1) {
            ans.insert({nums[i],nums[i]+k});
        }
    }
}

int main() {
    return 0;
}