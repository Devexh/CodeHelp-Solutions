#include <bits/stdc++.h>
using namespace std;
//! Important Questions

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

void levelOrderTraversal(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL); //! Queue with marker

  // asli traversal shuru
  while (!q.empty()) { //! galti hone ka chances hai idhar
    TreeNode *front = q.front();
    q.pop();

    if (front == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      // valid node
      cout << front->data << " ";

      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    }
  }
}

int searchInorder(int inOrder[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (inOrder[i] == target) {
      return i;
    }
  }
  return -1;
}

void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap) {
  for (int i = 0; i < size; i++) {
    int element = inOrder[i];
    int index = i;
    valueToIndexMap[element] = index;
  }
}

TreeNode *constructTreeFromPreAndInorderTraversal(map<int, int> &valToIndexMap,
                                                  int preOrder[], int inOrder[],
                                                  int &preIndex,
                                                  int inOrderStart,
                                                  int inOrderEnd, int size) {
  // base case //! preIndex ko by reference pass karna padega warna wapas jaane
  //! time vo decrement hone ke jagah 0 ho jayega
  if (preIndex >= size || inOrderStart > inOrderEnd) {
    return NULL;
  }
  // 1 case solve karna
  int element = preOrder[preIndex];
  preIndex++;
  TreeNode *root = new TreeNode(element);
  // element search karna padega in inOrder
  // int position = searchInorder(inOrder, size, element);
  int position = valToIndexMap[element];
  // recursion sambhal lega
  root->left = constructTreeFromPreAndInorderTraversal(
      valToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1,
      size);
  root->right = constructTreeFromPreAndInorderTraversal(
      valToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd,
      size);
  return root;
}

int main() {
  int inOrder[] = {10, 8, 6, 2, 4, 12};
  int preOrder[] = {2, 8, 10, 6, 4, 12};
  int size = 6;
  int preOrderIndex = 0;
  int inOrderStart = 0;
  int inOrderEnd = 5;
  map<int, int> valToIndexMap;
  createMapping(inOrder, size, valToIndexMap);

  TreeNode *root = constructTreeFromPreAndInorderTraversal(
      valToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd,
      size);
  cout << "Printing the entire tree: " << endl;
  levelOrderTraversal(root);

  return 0;
}