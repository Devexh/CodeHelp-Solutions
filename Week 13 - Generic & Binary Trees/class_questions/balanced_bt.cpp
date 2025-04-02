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

int height(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  int height = max(leftHeight, rightHeight) + 1;
  return height;
}

bool isBalanced(TreeNode *root) {
  // base case
  if (root == NULL) {
    return true;
  }

  // curr Node - solve
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  int diff = abs(leftHeight - rightHeight);

  bool currNodeAns = (diff <= 1);

  bool leftAns = isBalanced(root->left);
  bool rightAns = isBalanced(root->right);

  if (currNodeAns && leftAns && rightAns) {
    return true;
  } else {
    return false;
  }
}

int main() { return 0; }
