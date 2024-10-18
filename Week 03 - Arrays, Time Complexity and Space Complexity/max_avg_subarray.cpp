#include <bits/stdc++.h>
using namespace std;

double bruteForce(vector<int>& nums, int& k) { //? O(n^2)
    int maxSum = INT_MIN;
    int i = 0, j = k-1;
    while (j<nums.size()) {
        int sum = 0;
        for (int y=i; y<=j; ++y) {
            sum += nums[y];
        }
        maxSum = max(maxSum, sum);
        ++j,++i;
    }
    double maxAvg = maxSum / (double)k; //* use of explicit typecasting
    return maxAvg;
}

//TODO: Sliding Window Method
double slidingWindowMethod(vector<int>& nums, int& k) { //* O(n)
    int i = 0, j = k - 1;
    int sum = 0;
    for (int y = i; y <= j; ++y) {
        sum += nums[y];
    }
    int maxSum = sum;
    j++;
    while(j < nums.size()) {
        sum -= nums[i++]; //? since j has already been shifted forward in the former code therefore this code is meaningful
        sum += nums[j++];
        maxSum = max(maxSum, sum);
    }
    double maxAvg = maxSum / (double)k; //* use of explicit typecasting
    return maxAvg;
}

double findMaxAverage(vector<int>& nums, int k) {
    return slidingWindowMethod(nums, k);
}

int main() {
    return 0;
}