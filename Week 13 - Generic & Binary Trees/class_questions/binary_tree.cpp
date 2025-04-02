#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

// it returns root node of the created tree
Node *createTree() {
  cout << "Enter the value for Node: " << endl;
  int data;
  cin >> data;

  if (data == -1) {
    return NULL;
  }
  // Step1: create Node
  Node *newNode = new Node(data);
  // Step2: Create left Subtree
  cout << "Left of Node: " << newNode->data << endl;
  newNode->left = createTree();
  // Step3: Create Right Subtree
  cout << "Right of Node: " << newNode->data << endl;
  newNode->right = createTree();
  return newNode;
}

int main() {

  Node *root = createTree();

  return 0;
}