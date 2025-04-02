#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(vector<int> &nums, int curr, int prev) {
  // base case
  if (curr >= nums.size()) {
    return 0;
  }

  int include = 0;
  if (prev == -1 || nums[curr] > nums[prev]) {
    include =
        1 + solveUsingRecursion(nums, curr + 1,
                                curr); //! previous +1 hota to vo nahi chalta
  }
  int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);
  int ans = max(include, exclude);
  return ans;
}

//! MEMOIZATION
int solveUsingMem(vector<int> &nums, int curr, int prev,
                  vector<vector<int>> &dp) {
  // base case
  if (curr >= nums.size()) {
    return 0;
  }
  // if ans already exists
  if (dp[curr][prev + 1] !=
      -1) { //? since value of prev is -1 therefore we shift the index of prev
    return dp[curr][prev + 1];
  }

  int include = 0;
  if (prev == -1 || nums[curr] > nums[prev]) {
    include = 1 + solveUsingMem(nums, curr + 1, curr,
                                dp); //! previous +1 hota to vo nahi chalta
  }
  int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);
  dp[curr][prev + 1] = max(include, exclude);
  return dp[curr][prev + 1];
}

//! TABULATION
int solveUsingTabulation(vector<int> &nums) { //! INDEX SHIFTING
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
    for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {
      int include = 0;
      if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
        include = 1 + dp[curr_index + 1]
                        [curr_index + 1]; //! previous +1 hota to vo nahi chalta
      }
      int exclude = 0 + dp[curr_index + 1][prev_index + 1];
      dp[curr_index][prev_index + 1] = max(include, exclude);
    }
  }
  return dp[0][0];
}

//! SPACE-OPTIMISATION
int solveUsingTabulationSO(vector<int> &nums) { //! INDEX SHIFTING
  int n = nums.size();
  // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> currRow(n + 1, 0);
  vector<int> nextRow(n + 1, 0);

  for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
    for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {
      int include = 0;
      if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
        include =
            1 + nextRow[curr_index + 1]; //! previous +1 hota to vo nahi chalta
      }
      int exclude = 0 + nextRow[prev_index + 1];
      currRow[prev_index + 1] = max(include, exclude);
    }
    // Shifting
    nextRow = currRow;
  }
  return nextRow[0];
}

int solveUsingBS(vector<int> &nums) {
  vector<int> ans;
  // initial state
  ans.push_back(nums[0]);
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > ans.back()) {
      ans.push_back(nums[i]);
    } else {
      // just bada number exist karta hai
      int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
      // replace
      ans[index] = nums[i];
    }
  }
  return ans.size();
}

int lengthOfLIS(vector<int> &nums) {
  int curr = 0;
  int prev = -1;
  int n = nums.size();
  //  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  int ans = solveUsingTabulation(nums);
  return ans;
}

int main() { return 0; }
