#include <iomanip>
#include <iostream>

using namespace std;

void pauseProgram();

struct DynamicArray {
  int *arr, size, capacity;
  DynamicArray() : arr(new int[5]), size(-1), capacity(5) {} // constructor
  ~DynamicArray();                                           // destructor
  void insert(int d);
  void increaseCapacity();
  int operator[](int pos) { return arr[pos]; } // square brackets operator
};

bool isPrime(int num) {
  if (num <= 1)
    return 0;
  if (num == 2 || num == 3) {
    return 1;
  }
  for (int i = 2; i < num / 2 + 1; i++) {
    if (!(num % i)) {
      return 0;
    }
  }
  return 1;
}

bool isAdditivePrime(int num) {
  if (!isPrime(num)) {
    return false;
  }
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return isPrime(sum);
}

class BST {
public:
  class Node {
  public:
    int val;
    Node *left, *right;
    Node(int d) : val(d), left(nullptr), right(nullptr) {}
  };
  Node *root;
  BST() : root(nullptr) {}
  void insert_Rec(Node *&n, int d);
  void delete_Rec(Node *&n, int d);
  void display_Rec(Node *n, int space);
  void Traversal(int c);
  void Preorder_Rec(Node *n, DynamicArray &nums);
  void Inorder_Rec(Node *n, DynamicArray &nums);
  void Postorder_Rec(Node *n, DynamicArray &nums);
  bool search_Rec(Node *n, int d);
  Node *FindMin_Iter(Node *n);
};

int main() {
  BST tree;
  int n, c;
  while (1) {
    cout << "\n"
         << setw(30) << setfill('=') << "\n";
    cout << "---Binary Tree Operations---" << endl;
    cout << "[0]  Exit" << endl;
    cout << "[1]  Insert Node" << endl;
    cout << "[2]  Delete Node" << endl;
    cout << "[3]  Search" << endl;
    cout << "[4]  Pre-Order Traversal" << endl;
    cout << "[5]  In-Order Traversal" << endl;
    cout << "[6]  Post-Order Traversal" << endl;
    cout << setw(30) << setfill('=') << "\n";
    cout << "Enter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
      break;
    case 1:
      cout << "Enter num to insert: ";
      cin >> n;
      tree.insert_Rec(tree.root, n);
      break;
    case 2:
      cout << "\nEnter num to delete: ";
      cin >> n;
      tree.delete_Rec(tree.root, n);
      break;
    case 3:
      cout << "\nEnter num to search: ";
      cin >> n;
      cout << "\nSearch result: " << ((tree.search_Rec(tree.root, n)) ? "Element found!" : "Element not found!");
      break;
    case 4:
    case 5:
    case 6:
      tree.Traversal(c);
      break;
    default:
      break;
    }
    tree.display_Rec(tree.root, 10);
    pauseProgram();
  }
}

void BST::insert_Rec(Node *&n, int d) {
  if (!n) {
    n = new Node(d);
    return;
  }
  if (d < n->val) {
    insert_Rec(n->left, d);
  } else if (d > n->val) {
    insert_Rec(n->right, d);
  } else {
    cout << "\nValue " << d << " already in tree";
  }
}

void BST::delete_Rec(Node *&n, int d) {
  if (!n) {
    cout << "\nValue " << d << " does not exist in tree";
  }
  if (d < n->val) {
    delete_Rec(n->left, d);
  } else if (d > n->val) {
    delete_Rec(n->right, d);
  } else {
    if (!n->left && !n->right) {
      // case 1: has no child
      delete n;
      n = nullptr;
    } else if (n->left && !n->right) {
      // case 2: has left child but no right child
      Node *temp = n;
      n = n->left;
      delete temp;
      temp = nullptr;
    } else if (!n->left && n->right) {
      // case 3: has right child but no left child
      Node *temp = n;
      n = n->right;
      delete temp;
      temp = nullptr;
    } else {
      // case 4: has both left and right child
      Node *minRight = FindMin_Iter(n->right);
      int temp = minRight->val;
      n->val = temp;
      delete_Rec(n->right, temp);
    }
  }
}

void BST::display_Rec(Node *n, int space) {
  if (!n) {
    return;
  }
  display_Rec(n->right, space + 10);
  cout << endl;

  if (n != root) {

    for (int i = 10; i < space + 8; i++) {
      cout << " ";
    }
    cout << n->val << endl;
  } else {
    cout << "Root -> " << n->val << endl;
  }

  display_Rec(n->left, space + 10);
}

void BST::Traversal(int c) {
  DynamicArray nums;
  switch (c) {
  case 4:
    cout << "\nPre-order Traversal: ";
    Preorder_Rec(root, nums);
    break;
  case 5:
    cout << "\nIn-order Traversal: ";
    Inorder_Rec(root, nums);
    break;
  case 6:
    cout << "\nPost-order Traversal: ";
    Postorder_Rec(root, nums);
    break;
  }
  for (int i = 0; i <= nums.size; i++) {
    cout << nums[i] << " ";
  }
  cout << "\nAdditive Prime numbers:\n";
  for (int i = 0; i <= nums.size; i++) {
    if (isAdditivePrime(nums[i])) {
      cout << nums[i] << " - Position " << i + 1 << endl;
    }
  }
}

void BST::Preorder_Rec(Node *n, DynamicArray &nums) {
  if (!n) {
    return;
  }
  nums.insert(n->val);
  Preorder_Rec(n->left, nums);
  Preorder_Rec(n->right, nums);
}

void BST::Inorder_Rec(Node *n, DynamicArray &nums) {
  if (!n) {
    return;
  }
  Inorder_Rec(n->left, nums);
  nums.insert(n->val);

  Inorder_Rec(n->right, nums);
}

void BST::Postorder_Rec(Node *n, DynamicArray &nums) {
  if (!n) {
    return;
  }
  Postorder_Rec(n->left, nums);
  Postorder_Rec(n->right, nums);
  nums.insert(n->val);
}

bool BST::search_Rec(Node *n, int d) {
  if (!n) {
    return false;
  }
  if (d < n->val) {
    search_Rec(n->left, d);
  } else if (d > n->val) {
    search_Rec(n->right, d);
  } else {
    return true;
  }
}

BST::Node *BST::FindMin_Iter(Node *n) {
  while (n->left) {
    n = n->left;
  }
  return n;
}

DynamicArray::~DynamicArray() {
  delete[] arr;
  arr = nullptr;
}

void DynamicArray::insert(int d) {
  size++;
  if (size >= capacity) {
    increaseCapacity();
  }
  arr[size] = d;
}

void DynamicArray::increaseCapacity() {
  capacity *= 2;
  int *newArr = new int[capacity];
  for (int i = 0; i <= size; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void pauseProgram() {
  cin.ignore();
  cout << "\n\nPress Enter to continue . . . ";
  cin.get();
  system("cls");
}
