#include <iostream>
#include <queue>

using namespace std;

class BST {
private:
  class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
  };

  void recInsert(Node *&n, int d) {
    if (!n) {
      n = new Node(d);
      return;
    }
    if (d < n->data) {
      recInsert(n->left, d);
    } else {
      recInsert(n->right, d);
    }
  }

  void preOrder(Node *n) {
    if (!n) {
      return;
    }
    cout << n->data << " ";
    preOrder(n->left);
    preOrder(n->right);
  }

  void InOrder(Node *n) {
    if (!n) {
      return;
    }
    InOrder(n->left);
    cout << n->data << " ";
    InOrder(n->right);
  }

  void postOrder(Node *n) {
    if (!n) {
      return;
    }
    postOrder(n->left);
    postOrder(n->right);
    cout << n->data << " ";
  }

public:
  Node *root;
  BST() : root(nullptr) {}

  void insert(int d) {
    recInsert(root, d);
  }

  void printDepthFirst() {
    cout << "\nOutput (PreOrder): ";
    preOrder(root);
    cout << "\nOutput (InOrder): ";
    InOrder(root);
    cout << "\nOutput (PostOrder): ";
    postOrder(root);
  }

  void printBreadthFirst() {
    cout << "\n\nOutput (BreadthFirst): ";
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      auto curr = q.front();
      if (curr) {
        if (curr->left) {
          q.push(curr->left);
        }
        if (curr->right) {
          q.push(curr->right);
        }
      }
      cout << curr->data << " ";
      q.pop();
    }
  }

  void myDisplay(Node *n, int spaces) {
    if (!n) {
      return;
    }

    myDisplay(n->right, spaces + 10);
    cout << endl;

    if (n == root) {
      cout << "Root-> ";
    } else {
      for (int i = 10; i < spaces + 7; i++) {
        cout << " ";
      }
    }

    cout << n->data << endl;

    myDisplay(n->left, spaces + 10);
  }
};

int main() {
  BST tree;
  int num[10] = {5, 4, 8, 9, 1, 6, 3, 2, 7, 10};
  for (int n : num) {
    tree.insert(n);
  }

  tree.printDepthFirst();
  tree.printBreadthFirst();

  tree.myDisplay(tree.root, 10);
}
