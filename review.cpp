#include <iostream>

using namespace std;

class Tree {
public:
  class Node {
  public:
    int val;
    Node *left, *right;
    Node(int d) : val(d), left(nullptr), right(nullptr) {}
  };
  Node *root;
  Tree() : root(nullptr) {}
  void insert(Node *&n, int d);
  void display(Node *n, int space) const;
};

int main() {
  Tree t;
  srand(time(nullptr));
  for (int i = 0; i < 10; i++) {
    int n = (rand() % 20) + 1;
    t.insert(t.root, n);
  }
  t.display(t.root, 10);
}

void Tree::insert(Node *&n, int d) {
  if (!n) {
    n = new Node(d);
    return;
  }
  if (d < n->val) {
    insert(n->left, d);
  } else if (d > n->val) {
    insert(n->right, d);
  } else {
    cout << d << " alread in tree";
  }
}

void Tree::display(Node *n, int space) const {
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
