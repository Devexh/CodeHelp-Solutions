#include <bits/stdc++.h>
using namespace std;

//! BFS Breadth First Search; DFS Depth First Search

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

void PreOrderTraversal(Node *root) {
  // base case
  if (root == NULL) {
    return;
  }
  // N L R
  // N
  cout << root->data << " ";
  // L
  PreOrderTraversal(root->left);
  // R
  PreOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
  // LNR
  // base case
  if (root == NULL) {
    return;
  }
  // L
  inOrderTraversal(root->left);
  // N
  cout << root->data << " ";
  // R
  inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
  // LRN
  // base case
  if (root == NULL) {
    return;
  }
  // L
  postOrderTraversal(root->left);
  // R
  postOrderTraversal(root->right);
  // N
  cout << root->data << " ";
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL); //! Queue with marker

  // asli traversal shuru
  while (!q.empty()) { //! galti hone ka chances hai idhar
    Node *front = q.front();
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

int main() {

  Node *root = createTree();
  // cout << root->data << endl;

  cout << "Printing PreOrder: ";
  PreOrderTraversal(root);
  cout << endl;

  cout << "Printing InOrder: ";
  inOrderTraversal(root);
  cout << endl;

  cout << "Printing PostOrder: ";
  postOrderTraversal(root);
  cout << endl;

  cout << "Printing LevelOrder: ";
  levelOrderTraversal(root);
  cout << endl;

  return 0;
}
