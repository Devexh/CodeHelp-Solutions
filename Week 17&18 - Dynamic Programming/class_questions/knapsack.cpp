#include <bits/stdc++.h>
using namespace std; //! 2D Dynamic Programming

//! PLAIN RECURSION
int solveUsingRecursion(int capacity, int wt[], int profit[], int index,
                        int n) {
  // base case
  if (index == n - 1) {
    if (wt[index] <= capacity) {
      return profit[index];
    } else {
      return 0;
    }
  }
  // inc / exc
  int include = 0;
  if (wt[index] <= capacity) {
    include = profit[index] + solveUsingRecursion(capacity - wt[index], wt,
                                                  profit, index + 1, n);
  }
  int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index + 1, n);
  int ans = max(include, exclude);
  return ans;
}

void printDpArray(vector<vector<int>> &dp) {
  for (long long unsigned int i = 0; i < dp.size(); i++) {
    for (long long unsigned int j = 0; j < dp[0].size(); j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}

//! MEMOIZATION
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n,
                  vector<vector<int>> &dp) {
  // base case
  if (index == n - 1) {
    if (wt[index] <= capacity) {
      return profit[index];
    } else {
      return 0;
    }
  }

  // already exists
  if (dp[capacity][index] != -1) {
    return dp[capacity][index];
  }

  // inc / exc
  int include = 0;
  if (wt[index] <= capacity) {
    include = profit[index] +
              solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
  }
  int exclude = 0 + solveUsingMem(capacity, wt, profit, index + 1, n, dp);
  dp[capacity][index] = max(include, exclude);
  return dp[capacity][index];
}

//! TABULATION
int solveUsingTabulation(int capacity, int wt[], int profit[], int n) {
  vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
  // base case
  for (int row = 0; row <= capacity; row++) {
    dp[row][n] = 0;
  }
  for (int i = 0; i <= capacity; i++) {
    for (int j = n - 1; j >= 0; j--) {
      // inc / exc
      int include = 0;
      if (wt[j] <= i) {
        include = profit[j] + dp[i - wt[j]][j + 1];
      }
      int exclude = 0 + dp[i][j + 1];
      dp[i][j] = max(include, exclude);
    }
  }
  return dp[capacity][0];
}

int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n) {
  // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
  vector<int> next(capacity + 1, 0);
  vector<int> curr(capacity + 1, -1);
  // base case
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i <= capacity;
         i++) { //! Important Swapping the loops resulted in correct answer
      // inc / exc
      int include = 0;
      if (wt[j] <= i) {
        include = profit[j] + next[i - wt[j]];
      }
      int exclude = 0 + next[i];
      curr[i] = max(include, exclude);
    }
    // shifting
    next = curr;
  }
  return curr[capacity];
}

//! Another SPACE-OPTIMISED method
int solveUsingTabulationSO2(int capacity, int wt[], int profit[], int n) {
  // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
  vector<int> next(capacity + 1, 0);
  // vector<int> curr(capacity + 1, -1);
  //  base case
  for (int j = n - 1; j >= 0; j--) {
    for (int i = capacity; i >= 0;
         i--) { //! Important Swapping the loops resulted in correct answer
      // inc / exc
      int include = 0;
      if (wt[j] <= i) {
        include = profit[j] + next[i - wt[j]];
      }
      int exclude = 0 + next[i];
      next[i] = max(include, exclude);
    }
    // shifting
    // next = curr;
  }
  return next[capacity];
}

int main() {
  int capacity = 50;
  int wt[] = {10, 20, 30};
  int profit[] = {60, 100, 120};
  //   int index = 0;
  int n = 3;

  vector<vector<int>> dp(
      capacity + 1,
      vector<int>(n + 1,
                  -1)); //* capacity denotes rows, whereas index denotes column

  // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
  //   int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
  int ans = solveUsingTabulationSO2(capacity, wt, profit, n);
  cout << "Max Profit: " << ans << endl;

  return 0;
}
