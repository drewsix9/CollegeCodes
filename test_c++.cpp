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
  }
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
  cout << "\nrotating : " << n->val;
  Node *newPivot = n->right;
  Node *T1 = newPivot->left;
  // performing rotation
  n->right = nullptr;
  newPivot->left = n;
  n->right = T1;
  // update heights
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  newPivot->height = 1 + max(getHeight(newPivot->left), getHeight(newPivot->right));
  // return newpivot
  return newPivot;
}

AVL::Node *AVL::rotateRight(Node *n) {
  cout << "\nrotating : " << n->val;
  Node *newPivot = n->left;
  Node *T2 = newPivot->right;
  // performing rotation
  n->left = nullptr;
  newPivot->right = n;
  n->left = T2;
  // update heights
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  newPivot->height = 1 + max(getHeight(newPivot->left), getHeight(newPivot->right));
  // return newpivot
  return newPivot;
}
