#include <bits/stdc++.h>
using namespace std;

//? PLAIN RECURSION
int solveUsingRec(int n) {
  // base case - mandatory
  if (n == 0 || n == 1) {
    return n;
  }
  // processing - optional
  // recursive relation - mandatory
  int ans = solveUsingRec(n - 1) + solveUsingRec(n - 2);
  return ans;
}

//! TOP-DOWN APPROACH (REC+MEMOIZATION)
int solveUsingMem(int n, vector<int> &dp) {
  // base case - mandatory
  if (n == 0 || n == 1) {
    return n;
  }
  //! STEP3: if ans already exists then return ans
  if (dp[n] != -1) {
    return dp[n];
  }
  // processing - optional
  // recursive relation - mandatory
  //! STEP2: store and return using DP array
  dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
  return dp[n];
}

//! BOTTOM-UP APPROACH (TABULATION)
int solveUsingTabulation(int n) {
  //! STEP1: create dp array
  vector<int> dp(n + 1, -1);
  //! STEP2: Analyse base case and fill dp array
  dp[0] = 0;
  if (n == 0) {
    return dp[0];
  }
  dp[1] = 1;
  //! STEP3: Fill the remaining DP Array
  for (int i = 2; i <= n; i++) {
    // copy paste the recursive logic and replace recursion call with array
    // make sure dp array is using looping variable "i"
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  // answer return
  return dp[n];
}

//! SPACE-OPTIMISATION
int solveUsingSpaceOptimised(int n) {
  int prev = 0;
  if (n == 0) {
    return 0;
  }
  int curr = 1;
  if (n == 1) {
    return 1;
  }
  int ans;
  for (int i = 2; i <= n; i++) {
    ans = curr + prev;
    //! Important step prev and curr ko aage badhana
    prev = curr;
    curr = ans;
  }
  // answer return
  return ans;
}

int fib(int n) {
  // int ans = solveUsingRec(n);
  // return ans;
  //! STEP1: create DP Array
  vector<int> dp(n + 1, -1);
  int ans = solveUsingMem(n, dp);
  return ans;
}
int main() { return 0; }
