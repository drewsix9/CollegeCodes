#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
  if (num <= 1)
    return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool isAdditivePrime(int num) {
  if (!isPrime(num))
    return false;
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return isPrime(sum);
}
void pauseProgram();

class BST {
public:
  class Node {
  public:
    int value;
    Node *left, *right;
    Node(int d) : value(d), left(nullptr), right(nullptr) {}
  };
  Node *root;
  BST() : root(nullptr) {}
  void insert(Node *&n, int d);
  void remove(Node *&n, int d);
  void display(Node *n, int space);
  void traverse(int c);
  bool search(Node *n, int d);
  Node *findMin(Node *n);
  void traverseHelper(Node *n, vector<int> &nums, int c);
};

int main() {
  BST tree;
  int n, c;
  while (1) {
    cout << "\nBinary Tree Operations" << endl
         << "[0]  Exit\n[1]  Insert Node\n[2]  Delete Node\n[3]  Search\n[4]  Pre-Order Traversal\n[5]  In-Order Traversal\n[6]  Post-Order Traversal\n";
    cout << "Enter choice: ";
    cin >> c;
    if (c == 0)
      return 0;
    switch (c) {
    case 1:
      cout << "Enter num to insert: ";
      cin >> n;
      tree.insert(tree.root, n);
      break;
    case 2:
      cout << "\nEnter num to delete: ";
      cin >> n;
      tree.remove(tree.root, n);
      break;
    case 3:
      cout << "\nEnter num to search: ";
      cin >> n;
      cout << "\nSearch result: " << ((tree.search(tree.root, n)) ? "Element found!" : "Element not found!");
      break;
    case 4:
    case 5:
    case 6:
      tree.traverse(c);
      break;
    }
    tree.display(tree.root, 10);
    pauseProgram();
  }
}

void BST::insert(Node *&n, int d) {
  if (!n)
    n = new Node(d);
  else if (d < n->value)
    insert(n->left, d);
  else if (d > n->value)
    insert(n->right, d);
  else
    cout << "\nValue " << d << " already in tree";
}

void BST::remove(Node *&n, int d) {
  if (!n)
    cout << "\nValue " << d << " does not exist in tree";
  else if (d < n->value)
    remove(n->left, d);
  else if (d > n->value)
    remove(n->right, d);
  else {
    if (!n->left && !n->right) {
      delete n;
      n = nullptr;
    } else if (n->left && !n->right) {
      Node *temp = n;
      n = n->left;
      delete temp;
      temp = nullptr;
    } else if (!n->left && n->right) {
      Node *temp = n;
      n = n->right;
      delete temp;
      temp = nullptr;
    } else {
      Node *minRight = findMin(n->right);
      int temp = minRight->value;
      n->value = temp;
      remove(n->right, temp);
    }
  }
}

void BST::display(Node *n, int space) {
  if (!n)
    return;
  display(n->right, space + 10);
  cout << endl;
  if (n != root) {
    for (int i = 10; i < space + 8; i++)
      cout << " ";
    cout << n->value << endl;
  } else
    cout << "Root -> " << n->value << endl;
  display(n->left, space + 10);
}

void BST::traverse(int c) {
  vector<int> nums;
  switch (c) {
  case 4:
    cout << "\nPre-order Traversal: ";
    break;
  case 5:
    cout << "\nIn-order Traversal: ";
    break;
  case 6:
    cout << "\nPost-order Traversal: ";
    break;
  }
  traverseHelper(root, nums, c);
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << "\nAdditive Prime numbers:\n";
  for (int i = 0; i < nums.size(); i++)
    if (isAdditivePrime(nums[i]))
      cout << nums[i] << " - Position " << i + 1 << endl;
}

void BST::traverseHelper(Node *n, vector<int> &nums, int c) {
  if (!n)
    return;
  if (c == 4)
    nums.push_back(n->value);
  traverseHelper(n->left, nums, c);
  if (c == 5)
    nums.push_back(n->value);
  traverseHelper(n->right, nums, c);
  if (c == 6)
    nums.push_back(n->value);
}

bool BST::search(Node *n, int d) {
  if (!n)
    return false;
  if (d < n->value)
    return search(n->left, d);
  else if (d > n->value)
    return search(n->right, d);
  else
    return true;
}

BST::Node *BST::findMin(Node *n) {
  while (n->left)
    n = n->left;
  return n;
}

void pauseProgram() {
  cin.ignore();
  cout << "\n\nPress Enter to continue . . . ";
  cin.get();
  system("cls");
}