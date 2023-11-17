#include <algorithm>
#include <iostream>

using namespace std;

class AVLTree {
public:
  class Node {
  public:
    int val;
    Node *left, *right;
    int height;
    Node(int d) : val(d), left(nullptr), right(nullptr), height(1) {}
  };
  Node *root;
  AVLTree() : root(nullptr) {}
  void insert(Node *&n, int d);
  int getHeight(Node *n) { return (n ? n->height : 0); }
  int getBF(Node *n);
  void display(Node *n, int spaces);
  Node *rotateLeft(Node *n);
  Node *rotateRight(Node *n);
};

int main() {
  AVLTree tree;
  int n, c;
  while (1) {
    cout << "\n[0] - Exit\n[1] - Insert\n[2] - Get Height\nEnter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> n;
      tree.insert(tree.root, n);
      break;
    case 2:
      cout << "\nHeight: " << tree.getHeight(tree.root);
      break;
    }
    tree.display(tree.root, 10);
    // cout << "\nBalanced?: " << boolalpha << tree.isBal(tree.root);
  }
}

void AVLTree::insert(Node *&n, int d) {
  if (!n) {
    n = new Node(d);
    return;
  }
  if (d < n->val) {
    insert(n->left, d);
  } else if (d > n->val) {
    insert(n->right, d);
  } else {
    cout << "\nvalue already in tree!";
    return;
  }

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  int bf = getBF(n);
  if (bf > 1) {
    if (d < n->left->val) {
      // LL imbalance
      n = rotateRight(n);
    } else if (d > n->left->val) {
      // LR imbalance
      n->left = rotateLeft(n->left);
      n = rotateRight(n);
    }
  }
  if (bf < -1) {
    if (d > n->right->val) {
      // RR imbalance
      n = rotateLeft(n);
    } else if (d < n->right->val) {
      // RL imbalance
      n->right = rotateRight(n->right);
      n = rotateLeft(n);
    }
  }
}

int AVLTree::getBF(Node *n) {
  if (!n) {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

void AVLTree::display(Node *n, int spaces) {
  if (!n) {
    return;
  }
  display(n->right, spaces + 10);
  cout << endl;
  for (int i = 10; i < spaces; i++) {
    cout << " ";
  }
  cout << n->val << endl;
  display(n->left, spaces + 10);
}

AVLTree::Node *AVLTree::rotateRight(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));

  // Return new root
  return x;
}

AVLTree::Node *AVLTree::rotateLeft(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));

  // Return new root
  return y;
}