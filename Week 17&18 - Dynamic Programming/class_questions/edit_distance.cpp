#include <bits/stdc++.h>
using namespace std; //! Important Question

//! PLAIN RECURSION
int solveUsingRecursion(string &a, string &b, int i, int j) {
  // base case
  if (i == a.length()) {
    return b.length() - j;
  }
  if (j == b.length()) {
    return a.length() - i;
  }
  int ans = 0;
  if (a[i] == b[j]) {
    ans = 0 + solveUsingRecursion(a, b, i + 1, j + 1);
  } else {
    int replace = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    int insert = 1 + solveUsingRecursion(a, b, i, j + 1);
    int remove = 1 + solveUsingRecursion(a, b, i + 1, j);
    ans = min(insert, min(replace, remove));
  }
  return ans;
}

//! MEMOIZATION
int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> dp) {
  // base case
  if (i == a.length()) {
    return b.length() - j;
  }
  if (j == b.length()) {
    return a.length() - i;
  }

  // check if ans already exists
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = 0;
  if (a[i] == b[j]) {
    ans = 0 + solveUsingMem(a, b, i + 1, j + 1, dp);
  } else {
    int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
    int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);
    ans = min(insert, min(replace, remove));
  }
  dp[i][j] = ans;
  return dp[i][j];
}

//! TABULATION
int solveUsingTabulation(string &a, string &b, int i, int j) {
  vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));
  // base case
  for (int col = 0; col <= b.length(); col++) {
    dp[a.length()][col] = b.length() - col;
  }
  for (int row = 0; row <= a.length(); row++) {
    dp[row][b.length()] = a.length() - row;
  }

  for (int i_index = a.length() - 1; i >= 0; i--) {
    for (int j_index = b.length(); j_index >= 0; j--) {
      int ans = 0;
      if (a[i_index] == b[j_index]) {
        ans = 0 + dp[i_index + 1][j_index + 1];
      } else {
        int replace = 1 + dp[i_index + 1][j_index + 1];
        int insert = 1 + dp[i_index][j_index + 1];
        int remove = 1 + dp[i_index + 1][j_index];
        ans = min(insert, min(replace, remove));
      }
      dp[i_index][j_index] = ans;
    }
  }
  return dp[0][0];
}

int solveUsingTabulationSO(string &a, string &b, int i, int j) {
  //   vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));
  vector<int> curr(a.length() + 1, 0);
  vector<int> next(a.length() + 1, 0);

  //   for (int col = 0; col <= b.length(); col++) {
  //     dp[a.length()][col] = b.length() - col;
  //   }
  for (int row = 0; row <= a.length(); row++) {
    next[row] = a.length() - row;
  }

  for (int j_index = b.length(); j_index >= 0; j--) {
    // hr naye column ke last dabbe mein ans insert karo
    curr[a.length()] = b.length() - j_index;
    for (int i_index = a.length() - 1; i >= 0; i--) {
      int ans = 0;
      if (a[i_index] == b[j_index]) {
        ans = 0 + next[i_index + 1];
      } else {
        int replace = 1 + next[i_index + 1];
        int insert = 1 + next[i_index];
        int remove = 1 + curr[i_index + 1];
        ans = min(insert, min(replace, remove));
      }
      curr[i_index] = ans;
    }
    // Shifting
    next = curr;
  }
  return next[0];
}

int minDistance(string word1, string word2) {
  int i = 0;
  int j = 0;
  vector<vector<int>> dp(word1.length() + 1,
                         vector<int>(word2.length() + 1, -1));
  int ans = solveUsingMem(word1, word2, i, j, dp);
  return ans;
}

int main() { return 0; }
