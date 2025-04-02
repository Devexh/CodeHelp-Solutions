#include <bits/stdc++.h>
using namespace std;

int solveUsingRec(vector<int> &coins, int amount) {
  // base case
  if (amount == 0) {
    return 0;
  }
  // recursive relation
  int mini = INT_MAX;
  for (int i = 0; i < coins.size(); i++) {
    // find answer using ith coin
    int recursionKaAns = 0;
    // call recursion only for valid amounts
    if (amount - coins[i] >= 0) {
      int recursionKaAns = solveUsingRec(coins, amount - coins[i]);
      // if valid answer
      if (recursionKaAns != INT_MAX) {
        // considering usage of ith coin
        int ans = 1 + recursionKaAns;
        mini = min(mini, ans);
      }
    }
  }
  return mini;
}

//! MEMOIZATION
int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp) {
  // base case
  if (amount == 0) {
    return 0;
  }

  // already answer exists in DP
  if (dp[amount] != -1) {
    return dp[amount];
  }
  // recursive relation
  int mini = INT_MAX;
  for (int i = 0; i < coins.size(); i++) {
    // find answer using ith coin
    int recursionKaAns = 0;
    // call recursion only for valid amounts
    if (amount - coins[i] >= 0) {
      int recursionKaAns = solveUsingMem(coins, amount - coins[i], dp);
      // if valid answer
      if (recursionKaAns != INT_MAX) {
        // considering usage of ith coin
        int ans = 1 + recursionKaAns;
        mini = min(mini, ans);
      }
    }
  }
  dp[amount] = mini; // storing for reuse purpose
  return dp[amount];
}

//! TABULATION
int solveUsingTabulation(vector<int> &coins, int amount) {
  // step1
  int n = amount;
  vector<int> dp(n + 1, INT_MAX);
  // step2
  dp[0] = 0;
  // for loop
  for (int value = 1; value <= amount; value++) {
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      if (value - coins[i] >= 0) {
        int recursionKaAns = dp[value - coins[i]];
        if (recursionKaAns != INT_MAX) {
          int ans = 1 + recursionKaAns;
          mini = min(mini, ans);
        }
      }
    }
    dp[value] = mini;
  }
  return dp[amount];
}

int coinChange(vector<int> &coins, int amount) {
  // int ans = solveUsingRec(coins, amount);
  int n = amount;
  vector<int> dp(n + 1, -1);
  int ans = solveUsingMem(coins, amount, dp);
  if (ans == INT_MAX) {
    return -1;
  } else {
    return ans;
  }
}

int main() { return 0; }
