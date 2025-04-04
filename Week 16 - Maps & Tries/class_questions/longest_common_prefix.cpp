#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  char value;
  TrieNode *children[26];
  int childCount;
  bool isTerminal;

  TrieNode(char val) {
    this->value = val;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    this->isTerminal = false;
    this->childCount = 0;
  }
};

// insertion
void insertWord(TrieNode *root, string word) {
  // base case
  if (word.length() == 0) {
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch - 'a';
  TrieNode *child;
  if (root->children[index] != NULL) {
    // present
    child = root->children[index];
  } else {
    // absent
    child = new TrieNode(ch);
    root->children[index] = child;
    root->childCount++;
  }

  // recursion
  insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word) {
  // base case
  if (word.length() == 0) {
    return root->isTerminal;
  }

  char ch = word[0];
  int index = ch - 'a';
  TrieNode *child;

  if (root->children[index] != NULL) {
    // present or found
    child = root->children[index];
  } else {
    // not found;
    return false;
  }
  // baaki recursion
  bool recursionKaAns = searchWord(child, word.substr(1));
  return recursionKaAns;
}

void deleteWord(TrieNode *root, string word) {
  if (word.length() == 0) {
    root->isTerminal = false; //! for insertion it will be true
    return;
  }
  // one case solution
  char ch = word[0];
  int index = ch - 'a';
  TrieNode *child;

  if (root->children[index] != NULL) {
    // present
    child = root->children[index];
  } else {
    // not present;
    return;
  }
  // baaki recursion sambhal lega
  deleteWord(child, word.substr(1));
}

void findLCP(string &ans, TrieNode *root) {
  // base case
  if (root->isTerminal == true) {
    return;
  }
  // abhi mein root node par hoon
  TrieNode *child;
  if (root->childCount == 1) {
    // child tak jao ans mein store karwao
    // child tak jao
    for (int i = 0; i < 26; i++) {
      if (root->children[i] != NULL) {
        child = root->children[i];
      }
    }
    // ans mein value store karwao
    ans.push_back(child->value);
  } else {
    return;
  }
  // ab recursion ki baari
  findLCP(ans, child);
}

string longestCommonPrefix(vector<string> &strs) {
  TrieNode *root = new TrieNode('-');
  // insert all strings
  for (auto str : strs) {
    insertWord(root, str);
  }
  string ans = "";
  // string str = strs[0];
  findLCP(ans, root);
  return ans;
}