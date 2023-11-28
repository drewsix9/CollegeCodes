#include <bits/stdc++.h>

using namespace std;

bool isBinary(string s) {
  for (char c : s) {
    if (c >= '2') {
      return false;
    }
  }
  return true;
}

class BSTtree {
  class Node {
  public:
    string val;
    Node *left, *right;
    Node(string d) : val(d), left(nullptr), right(nullptr) {}
  };

public:
  Node *root;
  BSTtree() : root(nullptr) {}
  void insert(Node *&n, string d);
  void display(Node *n, int space);
  void PreOrder(Node *n, vector<string> &arr);
  void InOrder(Node *n, vector<string> &arr);
  void PostOrder(Node *n, vector<string> &arr);
  void traversal(int n);
  void printArr(vector<string> &arr);
  void printBinaryOnly(vector<string> &arr);
  void deleteNode(Node *&n, string d);
};

int main() {
  BSTtree tree;
  string s;
  int c;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert\n[2] - PreOrder\n[3] - InOrder\n[4] - PostOrder\n[5] - Delete\nEnter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
      break;
    case 1:
      cout << "\nEnter num to insert: ";
      cin >> s;
      tree.insert(tree.root, s);
      break;
    case 2:
    case 3:
    case 4:
      tree.traversal(c);
      break;
    case 5:
      cout << "\nEnter num to be deleted: ";
      cin >> s;
      tree.deleteNode(tree.root, s);
      break;
    default:
      break;
    }
    cout << "\n"
         << setw(50) << setfill('_') << " " << endl;
    tree.display(tree.root, 10);
  }
}

void BSTtree::insert(Node *&n, string d) {
  if (!n) {
    n = new Node(d);
    return;
  }
  if (stof(d) < stof(n->val)) {
    insert(n->left, d);
  } else if (stof(d) > stof(n->val)) {
    insert(n->right, d);
  } else {
    cout << "\nValue already in tree";
  }
}

void BSTtree::display(Node *n, int space) {
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

void BSTtree::PreOrder(Node *n, vector<string> &arr) {
  if (!n) {
    return;
  }
  arr.push_back(n->val);
  PreOrder(n->left, arr);
  PreOrder(n->right, arr);
}

void BSTtree::InOrder(Node *n, vector<string> &arr) {
  if (!n) {
    return;
  }
  InOrder(n->left, arr);
  arr.push_back(n->val);
  InOrder(n->right, arr);
}

void BSTtree::PostOrder(Node *n, vector<string> &arr) {
  if (!n) {
    return;
  }
  PostOrder(n->left, arr);
  PostOrder(n->right, arr);
  arr.push_back(n->val);
}

void BSTtree::traversal(int n) {
  vector<string> arr;
  switch (n) {
  case 2:
    PreOrder(root, arr);
    cout << "\nPre-Order Traversal: ";
    printArr(arr);
    printBinaryOnly(arr);
    break;
  case 3:
    InOrder(root, arr);
    cout << "\nIn-Order Traversal: ";
    printArr(arr);
    printBinaryOnly(arr);
    break;
  case 4:
    PostOrder(root, arr);
    cout << "\nPost-Order Traversal: ";
    printArr(arr);
    printBinaryOnly(arr);
    break;
  default:
    break;
  }
}

void BSTtree::printArr(vector<string> &arr) {
  for (string n : arr) {
    cout << n << " ";
  }
}

void BSTtree::printBinaryOnly(vector<string> &arr) {
  cout << "\nBinary Search:\n";
  for (size_t i = 0; i < arr.size(); i++) {
    if (isBinary(arr[i])) {
      cout << setw(15) << setfill(' ') << " ";
      cout << setw(8) << left << arr[i];
      cout << " - Position " << i + 1 << endl;
    }
  }
}

void BSTtree::deleteNode(Node *&n, string d) {
  if (!n) {
    cout << "\nValue does not exist in tree";
    return;
  }
  if (stof(d) < stof(n->val)) {
    deleteNode(n->left, d);
  } else if (stof(d) > stof(n->val)) {
    deleteNode(n->right, d);
  } else {
    if (!n->left && !n->right) { // case 1: has no child
      n = nullptr;
    } else if (n->left && !n->right) { // case 2: has left child but no right child
      n->val = n->left->val;
      delete n->left;
      n->left = nullptr;
    } else if (!n->left && n->right) { // case 3: has right child but no left child
      n->val = n->right->val;
      delete n->right;
      n->right = nullptr;
    } else { // case 4: has both left and right child
      Node *minRight = n->right;
      while (minRight->left) {
        minRight = minRight->left;
      }
      string temp = minRight->val;
      n->val = temp;
      deleteNode(n->right, temp);
    }
  }
}
