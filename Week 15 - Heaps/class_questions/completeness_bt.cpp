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

void countNodes(TreeNode *root, int &count) {
  if (root == NULL) {
    return;
  }
  count++;
  countNodes(root->left, count);
  countNodes(root->right, count);
}

bool levelOrderTraversal(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  bool nullFound = false; //flag

  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();

    if (front == NULL) {
      nullFound = true;
    } else {
      if (nullFound) {
        return false;
      }
      q.push(front->left);
      q.push(front->right);
    }
  }
  return true;
}

bool isCompleteTree(TreeNode *root) {
  // int totalNodes = 0;
  // countNodes(root, totalNodes);
  // int lastNode = 0;
  return levelOrderTraversal(root);
  // if (lastNode > totalNodes) {
  //   return false;
  // } else {
  //   return true;
  // }
}

int main() { return 0; }
