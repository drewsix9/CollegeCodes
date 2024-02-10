#include <iostream>
#include <queue>

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
  void insert(int d);
  void display(Node *n, int space) const;
};

int main() {
  Tree t;
  int n, c;
  while (1) {
    cout << "\n[0] - Exit\n[1] - Insert\nEnter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "Enter input: ";
      cin >> n;
      t.insert(n);
      break;
    }
    t.display(t.root, 10);
  }
}

void Tree::insert(int d) {
  Node *newNode = new Node(d);
  if (!root) {
    root = newNode;
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    if (!curr->left) {
      curr->left = newNode;
      return;
    } else {
      q.push(curr->left);
    }
    if (!curr->right) {
      curr->right = newNode;
      return;
    } else {
      q.push(curr->right);
    }
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
