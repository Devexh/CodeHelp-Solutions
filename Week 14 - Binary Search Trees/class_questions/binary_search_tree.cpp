#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    this->data = value;
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

void inOrder(Node *root) {
  // LNR
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root) {
  // NLR
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root) {
  // LRN
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  inOrder(root->right);
  cout << root->data << " ";
}

Node *minValue(Node *root) {
  if (root == NULL) {
    cout << "NO MIN VALUE" << endl;
    return NULL;
  }
  Node *temp = root;
  while (temp->left != NULL) {
    temp = temp->left;
  }
  return temp;
}

Node *maxValue(Node *root) {
  if (root == NULL) {
    cout << "NO MAX VALUE" << endl;
    return NULL;
  }
  Node *temp = root;
  while (temp->right != NULL) {
    temp = temp->right;
  }
  return temp;
}

bool searchInBST(Node *root, int target) { //! O(n) / O(height) in terms of BST
                                           //! n is also denoted as height
  // base case
  if (root == NULL) {
    return false;
  }

  // 1 case to solve
  if (root->data == target) {
    return true;
  }
  // baaki recursion sambhal lega
  bool leftAns = false;
  bool rightAns = false;
  if (target > root->data) {
    rightAns = searchInBST(root->right, target);
  } else {
    leftAns = searchInBST(root->left, target);
  }

  return leftAns || rightAns;
}

Node *deleteFromBST(Node *root, int target) {
  // target ko dhundho
  // target ko delete karo

  if (root == NULL) {
    return NULL;
  }
  if (root->data == target) {
    // ab delete karenge
    // 4 cases

    if (root->left == NULL && root->right == NULL) {
      // 1 Case -> leaf node
      delete root;
      return NULL;
    }

    else if (root->left != NULL && root->right == NULL) {
      // 2 Case-> Left non null and right null
      Node *childSubTree = root->left;
      delete root;
      return childSubTree;
    }

    else if (root->left == NULL && root->right != NULL) {
      // 3 case -> left mein NULL and right NON NULL
      Node *childSubTree = root->right;
      delete root;
      return childSubTree;
    }

    else {
      // 4 case -> left NON NULL and right NON NULL
      // a ->  left subtree ki max value lao
      Node *maxi = maxValue(root->left);
      // replacement
      root->data = maxi->data;
      // delete actual maxi node
      root->left = deleteFromBST(root->left, maxi->data);
      return root;
    }

  } else if (root->data > target) {
    // left mein chalo
    root->left = deleteFromBST(root->left, target); //! yahan galti ho sakti hai
  } else {
    // right mein chalo
    root->right = deleteFromBST(
        root->right,
        target); //! updated tree lagane ke liye root->right/left karna padega
  }
  return root;
}

int main() {
  Node *root = NULL;
  createBST(root);

  levelOrderTraversal(root);

  cout << endl << "Inorder: "; //! Inorder of a BST is always SORTED
  inOrder(root);
  cout << endl << "Preorder: ";
  preOrder(root);
  cout << endl << "Postorder: ";
  postOrder(root);

  cout << endl;
  Node *minNode = minValue(root);
  if (minNode == NULL) {
    cout << "There is no node is tree, so no min value" << endl;
  } else {
    cout << "Min Value: " << minNode->data << endl;
  }

  Node *maxNode = maxValue(root);
  if (maxNode == NULL) {
    cout << "There is no node is tree, so no min value" << endl;
  } else {
    cout << "Max Value: " << maxNode->data << endl;
  }

  int target;
  cout << "Enter the value of target: " << endl;
  cin >> target;

  while (target != -1) {
    root = deleteFromBST(root, target);
    cout << "Printing level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Enter the value of target: " << endl;
    cin >> target;
  }

  //   int t;
  //   cout << "Enter the target: " << endl;
  //   cin >> t;

  //   while (t != -1) {
  //     bool ans = searchInBST(root, t);
  //     if (ans == true) {
  //       cout << "FOUND" << endl;
  //     } else {
  //       cout << "NOT FOUND" << endl;
  //     }

  //     cout << "Enter the target: " << endl;
  //     cin >> t;
  //   }

  return 0;
}
