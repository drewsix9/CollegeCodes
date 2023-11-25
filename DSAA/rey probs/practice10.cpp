#include <iostream>
#include <time.h>
#include <vector>

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
  int max(Node *n);
  int min(Node *n);
  void primeAddens(int n);
  int findPos(vector<int> arr, int val);
  void Traversal(int c);
  void insertRand();

private:
  void PreOrderRec(Node *n, vector<int> &arr);
  void InOrderRec(Node *n, vector<int> &arr);
  void PostOrderRec(Node *n, vector<int> &arr);
};

int main() {
  Tree t;
  int n, c;
  t.insertRand();
  while (1) {
    cout << "\n[0] - Exit\n[1] - Insert\n[2] - PreOrder\n[3] - InOrder\n[4] - PostOrder\nEnter choice: ";
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
    case 3:
    case 4:
      t.Traversal(c);
      break;
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

int Tree::max(Node *n) {
  if (!n->right) {
    return n->val;
  }
  return max(n->right);
}

int Tree::min(Node *n) {
  if (!n->left) {
    return n->val;
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

int Tree::findPos(vector<int> arr, int val) {
  int pos = 1;
  for (int n : arr) {
    if (n == val) {
      return pos;
    }
    pos++;
  }
}

void Tree::Traversal(int c) {
  vector<int> arr;
  switch (c) {
  case 2:
    PreOrderRec(this->root, arr);
    cout << "\nPreOrder Traversal:\n- ";
    break;
  case 3:
    InOrderRec(this->root, arr);
    cout << "\nInOrder Traversal:\n- ";
    break;
  case 4:
    PostOrderRec(this->root, arr);
    cout << "\nPostOrder Traversal:\n- ";
    break;
  }
  for (int n : arr) {
    cout << n << " ";
  }
  cout << "\nSmallest:\n";
  int smallest = min(this->root);
  cout << smallest << ", "
       << "position " << findPos(arr, smallest) << endl;
  primeAddens(smallest);

  cout << "\nLargest:\n";
  int largest = max(this->root);
  cout << largest << ", "
       << "position " << findPos(arr, largest) << endl;
  primeAddens(largest);
}

void Tree::PreOrderRec(Node *n, vector<int> &arr) {
  if (!n) {
    return;
  }
  arr.push_back(n->val);
  PreOrderRec(n->left, arr);
  PreOrderRec(n->right, arr);
}

void Tree::InOrderRec(Node *n, vector<int> &arr) {
  if (!n) {
    return;
  }
  InOrderRec(n->left, arr);
  arr.push_back(n->val);
  InOrderRec(n->right, arr);
}

void Tree::PostOrderRec(Node *n, vector<int> &arr) {
  if (!n) {
    return;
  }
  PostOrderRec(n->left, arr);
  PostOrderRec(n->right, arr);
  arr.push_back(n->val);
}

void Tree::insertRand() {
  srand(time(nullptr));
  for (int i = 0; i < 10; i++) {
    int n = 1 + (rand() % 50);
    this->insert(this->root, n);
  }
}
