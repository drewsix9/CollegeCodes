#include <iostream>

using namespace std;

bool isPrime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

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
  Node *max(Node *n);
  Node *min(Node *n);
  void primeAddens(int n);
};

int main() {
  Tree t;
  int n, c;
  while (1) {
    cout << "\n[0] - Exit\n[1] - Insert\n[2] - Find Max\n[3] - Find Min\n[4] - Prime Addens of Max\n[5] - Prime Addens of Min\nEnter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "Enter input: ";
      cin >> n;
      t.insert(t.root, n);
      break;
    case 2:
      cout << "\nMax: " << t.max(t.root)->val;
      break;
    case 3:
      cout << "\nMin: " << t.min(t.root)->val;
      break;
    case 4:
      cout << "\nPrime Addens of the Max value:\n";
      t.primeAddens(t.max(t.root)->val);
      break;
    case 5:
      cout << "\nPrime Addens of the Min value:\n";
      t.primeAddens(t.min(t.root)->val);
    }
    t.display(t.root, 10);
  }
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
    cout << d << " is already in tree";
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

Tree::Node *Tree::max(Node *n) {
  if (!n->right) {
    return n;
  }
  return max(n->right);
}

Tree::Node *Tree::min(Node *n) {
  if (!n->left) {
    return n;
  }
  return min(n->left);
}

void Tree::primeAddens(int n) {
  for (int i = 2; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i + j == n && isPrime(i) && isPrime(j)) {
        cout << i << "+" << j << endl;
      }
    }
  }
}