// BST, choose what to ban, numbers with lteer 'o' or 'u'

#include <iostream>
#include <set>
using namespace std;

int countDig(int n) {
  if (n <= 0) {
    return 0;
  }
  return 1 + countDig(n / 10);
}

bool hasLetterO(int n) {
  set<int> set = {1, 2, 4};
  if (n == 14)
    return true;
  if (n == 12)
    return false;
  if (n == 0)
    return false;
  int place = 1;
  while (n > 0) {
    int rem = n % 10;
    if (set.count(rem) > 0 && !(place == 2 && rem == 2)) { // is in set
      return true;
    }
    place++;
    n /= 10;
  }
  return false;
}

bool hasLetterU(int n) {
  set<int> set = {4};
  if (n == 12)
    return false;
  if (n == 0)
    return false;
  while (n > 0) {
    int rem = n % 10;
    if (set.count(rem) > 0) { // is in set
      return true;
    }
    n /= 10;
  }
  return false;
}

class BST {
public:
  class Node {
  public:
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
  };
  void preOrder(Node *node, char c) {
    if (!node) {
      return;
    }
    if ((c == 'u' || c == 'U') && !hasLetterU(node->data)) {
      cout << node->data << " ";
    } else if ((c == 'o' || c == 'O') && !hasLetterO(node->data)) {
      cout << node->data << " ";
    }
    preOrder(node->left, c);
    preOrder(node->right, c);
  }

  void inOrder(Node *node, char c) {
    if (!node) {
      return;
    }
    inOrder(node->left, c);
    if ((c == 'u' || c == 'U') && !hasLetterU(node->data)) {
      cout << node->data << " ";
    } else if ((c == 'o' || c == 'O') && !hasLetterO(node->data)) {
      cout << node->data << " ";
    }
    inOrder(node->right, c);
  }

  void postOrder(Node *node, char c) {
    if (!node) {
      return;
    }
    postOrder(node->left, c);
    postOrder(node->right, c);
    if ((c == 'u' || c == 'U') && !hasLetterU(node->data)) {
      cout << node->data << " ";
    } else if ((c == 'o' || c == 'O') && !hasLetterO(node->data)) {
      cout << node->data << " ";
    }
  }

  Node *root;
  BST();

  void insert(Node *&node, int d);
  void deleteNode(Node *&node, int d);
  void banMenu(char c);
  void traversalMenu(char c);
  void display(Node *node, int spaces);
};

int main() {
  BST tree;
  int num, choice;
  while (1) {
    cout << "\n\n-----Binary Tree Operations-----\n[0]: Exit\n[1]: Insert node\n[2]: Delete node\n[3]: Letter ban\nEnter choice: ";
    cin.clear();
    cin.ignore();
    cin >> choice;
    char c;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter node to insert: ";
      cin.clear();
      cin.ignore();
      cin >> num;
      tree.insert(tree.root, num);
      break;
    case 2:
      cout << "\nEnter node to delete: ";
      cin.clear();
      cin.ignore();
      cin >> num;
      tree.deleteNode(tree.root, num);
      break;
    case 3:
      cout << "\n[o] O-Ban\n[u] U-Ban\nEnter what letter to ban: ";
      cin.clear();
      cin.ignore();
      cin >> c;
      tree.banMenu(c);
      break;
    case 4:

    default:
      break;
    }
    tree.display(tree.root, 10);
  }
}

void BST::insert(Node *&node, int d) {
  if (!node) {
    node = new Node(d);
    return;
  }
  if (d < node->data) {
    insert(node->left, d);
  } else if (d > node->data) {
    insert(node->right, d);
  }
}

void BST::deleteNode(Node *&node, int d) {
  if (!node) {
    return;
  }
  if (d < node->data) {
    deleteNode(node->left, d);
  } else if (d > node->data) {
    deleteNode(node->right, d);
  } else {
    // Node to be deleted is found
    if (!node->left && !node->right) {
      // Case 1: Node has no children
      delete node;
      node = nullptr;
    } else if (!node->left && node->right) {
      // Case 2: Node has only right child
      Node *temp = node;
      node = node->right;
      delete temp;
    } else if (node->left && !node->right) {
      // Case 3: Node has only left child
      Node *temp = node;
      node = node->left;
      delete temp;
    } else {
      // Case 4: Node has both left and right children
      Node *minRight = node->right;
      // takes the minimum node from the right subtree
      while (minRight->left) {
        minRight = minRight->left;
      }
      int temp = minRight->data;
      node->data = temp;
      deleteNode(node->right, minRight->data);
    }
  }
}

void BST::banMenu(char c) {
  if (c == 'u' || c == 'U') {
    cout << "\nBanning numbers with letter u";
  } else if (c == 'o' || c == 'O') {
    cout << "\nBanning numbers with letter o";
  }
  traversalMenu(c);
}

void BST::traversalMenu(char c) {
  while (1) {
    int choice;
    cout << "\n\n-----Tree Traversal-----\n[0]: Back\n[1]: Preorder\n[2]: Inorder\n[3]: Postorder\n[4]: Breadth First: \nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      system("cls");
      cout << "\nReturning to menu...";
      return;
    case 1:
      cout << "\nPreorder: ";
      preOrder(root, c);
      break;
    case 2:
      cout << "\nInorder: ";
      inOrder(root, c);
      break;
    case 3:
      cout << "\nPostorder: ";
      postOrder(root, c);
      break;
      break;
    }
    cin.ignore();
    cout << "\nPress enter to continue...";
    cin.get();
  }
}

BST::BST() {
  cout << "\nEnter root node: ";
  int d;
  cin >> d;
  root = new Node(d);
}

void BST::display(Node *node, int spaces) {
  if (!node) {
    return;
  }
  display(node->right, spaces + 10);
  cout << endl;
  if (node == root) {
    cout << "Root -> ";
  } else {
    for (int i = 10; i < spaces + 7; i++) {
      cout << " ";
    }
  }
  cout << node->data;
  display(node->left, spaces + 10);
}