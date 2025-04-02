#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

void solve(TreeNode *root, int targetSum, vector<vector<int>> &ans,
           vector<int> temp, int sum) {
  // base case
  if (root == NULL) {
    return;
  }
  // 1: Case solve karna hai!!
  sum += root->data;
  temp.push_back(root->data);

  // extra case
  if (root->left == NULL && root->right == NULL) {
    // verify
    if (sum == targetSum) {
      // store temp path in final ans array
      ans.push_back(temp);
    } else {
      return;
    }
  }

  // baaki recursion sambhal lega
  solve(root->left, targetSum, ans, temp, sum);
  solve(root->right, targetSum, ans, temp, sum);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  vector<vector<int>> ans;
  vector<int> temp;
  int sum = 0;
  solve(root, targetSum, ans, temp, sum);
  return ans;
}

int main() { return 0; }
