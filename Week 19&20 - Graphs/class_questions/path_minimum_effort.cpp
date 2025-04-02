#include <bits/stdc++.h>
using namespace std; //! Greedy Algorithm

bool isSafe(int newX, int newY, int row, int col, vector<vector<int>> &diff,
            int currX, int currY) {
  if (newX >= 0 && newY >= 0 && newX < row && newY < col &&
      diff[currX][currY] < diff[newX][newY]) {
    return true;
  } else {
    return false;
  }
}

int minimumEffortPath(vector<vector<int>> &heights) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      mini;
  int row = heights.size();
  int col = heights[0].size();
  vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
  int destX = row - 1;
  int destY = col - 1;

  // initial state
  // set srcnode ka distance 0
  diff[0][0] = 0;
  // min heap me entry for src push karo
  mini.push({0, {0, 0}});

  while (!mini.empty()) {
    auto topPair = mini.top();
    mini.pop();
    int currDiff = topPair.first;
    pair<int, int> currNodeIndexPair = topPair.second;
    int currX = currNodeIndexPair.first;
    int currY = currNodeIndexPair.second;

    // now we can travel to all neightbours
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int newX = currX + dx[i];
      int newY = currY + dy[i];
      if (isSafe(newX, newY, row, col, diff, currX, currY)) {
        int maxDiff =
            max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
        // check can we update diff array
        diff[newX][newY] = min(diff[newX][newY], maxDiff);
        // entry create karo mean heap ke liye
        if (newX != destX || newY != destY) { //! Issue condition
          mini.push({diff[newX][newY], {newX, newY}});
        }
      }
    }
    return diff[destX][destY];
  }
}

int main() { return 0; }
