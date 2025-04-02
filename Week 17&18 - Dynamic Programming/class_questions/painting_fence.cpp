#include <bits/stdc++.h>
using namespace std; //! 1D Dynamic Programming 

//! PLAIN RECURSION
int solveUsingRecursion(int n, int k) {
  // base case
  if (n == 1) {
    return k;
  }
  if (n == 2) {
    return (k + k * (k - 1));
  }
  int ans =
      (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
  return ans;
}

//! MEMOIZATION
int solveUsingMem(int n, int k, vector<int> &dp) {
  // base case
  if (n == 1) {
    return k;
  }
  if (n == 2) {
    return (k + k * (k - 1));
  }
  // already exists
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp)) * (k - 1);
  return dp[n];
}

//! TABULATION
int solveUsingTabulation(int n, int k) {
  vector<int> dp(n + 1, -1);
  dp[1] = k;
  dp[2] = k + k * (k - 1);

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
  }
  return dp[n];
}

//! SPACE-OPTIMISATION
int solveUsingTabulationSO(int n, int k) {
  // vector<int> dp(n + 1, -1);
  int prev2 = k;
  int prev1 = k + k * (k - 1);
  int curr;
  if (n == 1) {
    return prev2;
  }
  if (n == 2) {
    return prev1;
  }

  for (int i = 3; i <= n; i++) {
    curr = (prev1 + prev2) * (k - 1);
    // shift
    prev2 = prev1;
    prev1 = curr;
  }
  return curr;
}

int main() {
  int n = 3;
  int k = 3;

  // vector<int> dp(n + 1, -1);
  int ans = solveUsingTabulationSO(n, k);
  cout << "Ans: " << ans << endl;

  return 0;
}
