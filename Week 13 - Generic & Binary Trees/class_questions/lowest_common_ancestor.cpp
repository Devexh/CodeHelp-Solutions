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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  // base case
  if (root == NULL) {
    return NULL;
  }
  if (root->data == p->data) {
    return p;
  }
  if (root->data == q->data) {
    return q;
  }
  TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
  TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
  if (leftAns == NULL && rightAns == NULL) {
    return NULL;
  } else if (leftAns != NULL && rightAns == NULL) {
    return leftAns;
  } else if (leftAns == NULL && rightAns != NULL) {
    return rightAns;
  } else {
    return root;
  }
}

int main() { return 0; }
