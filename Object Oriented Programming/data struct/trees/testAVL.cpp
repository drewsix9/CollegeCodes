#include <iostream>

using namespace std;

class AVLTree {
public:
  class Node {
  public:
    int val;
    Node *left, *right;
    Node(int d) : val(d), left(nullptr), right(nullptr) {}
  };
  AVLTree() : root(nullptr) {}
  Node *root;
  void insert(Node *&, int);
  void display(Node *, int);
  int getHeight(Node *);
  bool isBal(Node *);
  int getBF(Node *);
  Node *rotate(Node *);
  Node *LLimBalance(Node *);
  Node *RRimBalance(Node *);
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
    cout << "\nValue already in tree";
    return;
  }
  if (!isBal(n)) {
    n = rotate(n);
  }
}

void AVLTree::display(Node *n, int spaces) {
  if (!n) {
    return;
  }
  display(n->right, spaces + 10);
  cout << endl;
  if (n == this->root) {
    cout << "Root-> ";
  } else {
    for (int i = 10; i < spaces + 7; i++) {
      cout << " ";
    }
  }
  cout << n->val << " h=" << getHeight(n) << endl;
  display(n->left, spaces + 10);
}

int AVLTree::getHeight(Node *n) {
  if (!n) {
    return 0;
  }
  return 1 + max(getHeight(n->left), getHeight(n->right));
}

int AVLTree::getBF(Node *n) {
  return getHeight(n->left) - getHeight(n->right);
}

bool AVLTree::isBal(Node *n) {
  int bf = abs(getBF(n));
  return ((bf <= 1) ? true : false);
}

AVLTree::Node *AVLTree::LLimBalance(Node *n) {
  Node *newPivot = n->left;
  n->left = nullptr;
  n->right = nullptr;
  newPivot->right = n;
  return newPivot;
}

AVLTree::Node *AVLTree::RRimBalance(Node *n) {
  Node *newPivot = n->right;
  n->right = nullptr;
  n->right = nullptr;
  newPivot->left = n;
  return newPivot;
}

AVLTree::Node *AVLTree::rotate(Node *n) {
  // left Heavy
  if (getBF(n) >= 2) {
    if (getBF(n->left) >= 1) {
      // LL imbalance
      cout << "\nLL imbalance";
      return LLimBalance(n);
    } else {
      // LR imbalance
      cout << "\nLR imbalance";
      n->left = RRimBalance(n->left);
      return LLimBalance(n);
    }
  }
  // Right Heavy
  else if (getBF(n) <= -2) {
    if (getBF(n->right) <= -1) {
      // RR imbalance
      cout << "\nRR imbalance";
      return RRimBalance(n);
    } else {
      // RL imbalance
      cout << "\nRL imbalance";
      n->right = LLimBalance(n->right);
      return RRimBalance(n);
    }
  }
}
