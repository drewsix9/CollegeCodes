#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *left;
  Node *right;
  // Node(int val) : value(val), left(nullptr), right(nullptr) {}
  // both are thesame
  Node(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }
};

void insertNode(Node *&ptr, int val) {
  if (ptr == nullptr) {
    ptr = new Node(val);
  } else if (val < ptr->value) {
    insertNode(ptr->left, val);
  } else if (val > ptr->value) {
    insertNode(ptr->right, val);
  }
}

// creating the head of the tree
void createHead(Node *&root) {
  int val;
  cin >> val;
  root = new Node(val);
}

void constructNode(Node *&root) {
  createHead(root);
  int val;
  while (cin >> val && val != 0) {
    Node *ptr = root;
    insertNode(ptr, val);
  }
}

void printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
  }
}

int main() {
  Node *root = nullptr;
  constructNode(root);
  printTree(root);
  return 0;
}