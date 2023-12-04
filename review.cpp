#include <bits/stdc++.h>

using namespace std;

class BSTree {
public:
  class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
  };
  Node *root;
  BSTree() : root(nullptr) {}

  void insert(Node *&n, int val);
  void deleteNode(Node *&n, int val);
  void display(Node *n, int space);
};

int main() {
  BSTree bst;
  int n, c;
  while (1) {
    cout << "\n[0] Exit" << endl;
    cout << "[1] Insert" << endl;
    cout << "[2] Delete" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    switch (c) {
    case 0:
      exit(0);
    case 1:
      cout << "Enter value to insert: ";
      cin >> n;
      bst.insert(bst.root, n);
      break;
    case 2:
      cout << "Enter value to delete: ";
      cin >> n;
      bst.deleteNode(bst.root, n);
      break;
    }
    bst.display(bst.root, 10);
  }
}

void BSTree::insert(Node *&n, int val) {
  if (!n) {
    n = new Node(val);
    return;
  }
  if (val < n->val) {
    insert(n->left, val);
  } else if (val > n->val) {
    insert(n->right, val);
  } else {
    cout << "Duplicate value" << endl;
  }
}

void BSTree::deleteNode(Node *&n, int val) {
  if (!n) {
    cout << "Value not found" << endl;
    return;
  }
  if (val < n->val) {
    deleteNode(n->left, val);
  } else if (val > n->val) {
    deleteNode(n->right, val);
  } else {
    if (!n->left && !n->right) {
      delete n;
      n = nullptr;
    } else if (!n->left) {
      Node *temp = n;
      n = n->right;
      delete temp;
    } else if (!n->right) {
      Node *temp = n;
      n = n->left;
      delete temp;
    } else {
      Node *temp = n->right;
      while (temp->left) {
        temp = temp->left;
      }
      n->val = temp->val;
      deleteNode(n->right, temp->val);
    }
  }
}

void BSTree::display(Node *n, int space) {
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
