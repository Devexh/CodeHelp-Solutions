#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    // count method
    int zeros, ones, twos;
    zeros = ones = twos = 0;

    for (int i = 0; i<nums.size(); i++) {
        if (nums[i] == 0) {
            zeros++;
        }
        else if (nums[i] == 1) {
            ones++;
        }
        else {
            twos++;
        }
    }

    //spread
    int i = 0;
    while (zeros--) {
        nums[i] = 0;
        i++;
    }
    while (zeros--) {
        nums[i] = 1;
        i++;
    }
    while (zeros--) {
        nums[i] = 2;
        i++;
    }
}

//in-place 3 pointer approach
void sortColorAlt(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size()-1;
    while(m<=h){
        if (nums[m] == 0) {
            swap(nums[l], nums[m]);
            l++, m++;
        }
        else if (nums[m] == 1) {
            m++;
        }
        else {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main() {
    return 0;
}