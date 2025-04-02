#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insertIntoBST(Node *root, int data) {
  if (root == NULL) {
    root = new Node(data);
    return root;
  }
  // its not the first node
  if (data > root->data) {
    root->right = insertIntoBST(root->right, data);
  } else {
    root->left = insertIntoBST(root->left, data);
  }
  return root;
}

void createBST(Node *&root) {
  cout << "Enter data: " << endl;
  int data;
  cin >> data;

  while (data != -1) {
    root = insertIntoBST(root, data);
    cout << "Enter data: " << endl;
    cin >> data;
  }
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      if (temp->right != NULL) {
        q.push(temp->right);
      }
    }
  }
}

void storeInOrderTraversal(Node *root, vector<int> &in) { //! pass by reference
  if (root == NULL) {
    return;
  }
  // LNR
  storeInOrderTraversal(root->left, in);
  in.push_back(root->data);
  storeInOrderTraversal(root->right, in);
}

void replaceUsingPostOrder(Node *root, vector<int> in, int &index) {
  if (root == NULL) {
    return;
  }
  // LRN
  replaceUsingPostOrder(root->left, in, index);
  replaceUsingPostOrder(root->right, in, index);
  root->data = in[index];
  index++;
}

Node *convertBSTIntoMaxHeap(Node *root) {
  // 1 step: store inorder
  vector<int> inorder;
  storeInOrderTraversal(root, inorder);
  // Replace the node value with the sorted inorder values, using the post order
  // traversal
  int index = 0;
  replaceUsingPostOrder(root, inorder, index);
  return root;
}

int main() {
  Node *root = NULL;
  createBST(root);
  cout << "Printing the BST: " << endl;
  levelOrderTraversal(root);
  cout << endl;

  cout << endl << "Converting into Heap: " << endl;

  root = convertBSTIntoMaxHeap(root);
  cout << "Printing the Heap: " << endl;
  levelOrderTraversal(root);

  return 0;
}
