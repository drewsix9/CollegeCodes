#include <iostream>
#include <time.h>

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
  void display(Node *n, int space);
  int getHeight(Node *n);
  int getBF(Node *n);
};

int main() {
  AVL tree;
  srand(time(nullptr));
  for (int i = 0; i < 10; i++) {
    int n = rand() % 10;
    cout << "\nInserting: " << n;
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
    cout << "\nValue already exist";
  }
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

int AVL::getHeight(Node *n) {
  return (n ? n->val : 0);
}

int AVL::getBF(Node *n) {
  return getHeight(n->left) - getHeight(n->right);
}