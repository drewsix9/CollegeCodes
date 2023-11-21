#include <iostream>

using namespace std;

class AVL {
public:
  class Node {
  public:
    int val;
    Node *left, *right;
    int height;
    Node(int d) : val(d), left(nullptr), right(nullptr), height(1) {}
  };

  Node *root;
  AVL() : root(nullptr) {}

  void insert(Node *&n, int d);
  int getBF(Node *n);
  int getHeight(Node *n);
  void display(Node *n, int space);
  Node *rotateLeft(Node *n);
  Node *rotateRight(Node *n);
};

int main() {
  AVL tree;

  for (int i = 0; i < 10; i++) {
    int n = rand() % 100;
    tree.insert(tree.root, n);
  }
  tree.display(tree.root, 10);
}

void AVL::insert(Node *&n, int d) {
  if (!n) {
    n = new Node(d);
    return;
  }
  if (d < n->val) {
    insert(n->left, d);
  } else if (d > n->val) {
    insert(n->right, d);
  } else {
    cout << "\nValue already in tree.";
  }

  // update height
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;

  // insert check if balance here
  int bf = getBF(n);
  if (bf > 1) {
    if (d < n->left->val) {
      // LL
      n = rotateRight(n);
    } else if (d > n->left->val) {
      // LR
      n->left = rotateLeft(n->left);
      n = rotateRight(n);
    }
  }
  if (bf < -1) {
    if (d > n->right->val) {
      // RR
      n = rotateLeft(n);
    } else if (d < n->right->val) {
      // Rl
      n->right = rotateRight(n->right);
      n = rotateLeft(n);
    }
  }
}

int AVL::getBF(Node *n) {
  return getHeight(n->left) - getHeight(n->right);
}

int AVL::getHeight(Node *n) {
  if (!n) {
    return 0;
  }
  return n->height;
}

void AVL::display(Node *n, int space) {
  if (!n) {
    return;
  }
  display(n->right, space + 10);
  cout << endl;
  for (int i = 10; i < space; i++) {
    cout << " ";
  }
  cout << n->val << endl;
  display(n->left, space + 10);
}

AVL::Node *AVL::rotateLeft(Node *n) {
  Node *newPivot = n->right;
  Node *T1 = newPivot->left;
  n->right = nullptr;
  newPivot->left = n;
  n->right = T1;
  return n;
}

AVL::Node *AVL::rotateRight(Node *n) {
  Node *newPivot = n->left;
  Node *T2 = newPivot->right;
  n->left = nullptr;
  newPivot->right = n;
  n->left = T2;
  return n;
}
