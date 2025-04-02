#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &curr, vector<int> &prev) {
  //* curr -> bade wale dabbe
  //* prev -> chote wale dabbe
  if (prev[0] < curr[0] && prev[1] < curr[1]) {
    return true;
  } else {
    return false;
  }
}

int solveUsingTabulationSO(vector<vector<int>> &env) { //! INDEX SHIFTING
  int n = env.size();

  vector<int> currRow(n + 1, 0);
  vector<int> nextRow(n + 1, 0);

  for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
    for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {
      int include = 0;
      if (prev_index == -1 || check(env[curr_index], env[prev_index])) {
        // int heightToAdd = env[curr_index][2];
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

int maxEnvelopes(vector<vector<int>> &envelopes) {
  sort(envelopes.begin(), envelopes.end());
  int ans = solveUsingTabulationSO(envelopes);
  return ans;
}

int main() { return 0; }