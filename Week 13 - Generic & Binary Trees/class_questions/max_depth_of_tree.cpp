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

int maxDepth(TreeNode *root) {
  // base case
  if (root == NULL) {
    return 0;
  }

  int leftHeight = maxDepth(root->left);
  int rightHeight = maxDepth(root->right);
  int height = max(leftHeight, rightHeight) + 1;
  return height;
}

int maxDepthLevelOrder(TreeNode *root) {

  if (root == NULL) { //! check if tree is empty or not
    return 0;
  }

  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL); //! Queue with marker
  int count = 1;

  // asli traversal shuru
  while (!q.empty()) { //! galti hone ka chances hai idhar
    TreeNode *front = q.front();
    q.pop();

    if (front == NULL) {
      cout << endl;
      if (!q.empty()) {
        count++;
        q.push(NULL);
      }
    } else {
      // valid node
      // cout << front->data << " ";

      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    }
  }
  return count;
}

int main() { return 0; }
