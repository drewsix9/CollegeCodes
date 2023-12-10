// BST, print only prime additives

#include <iostream>
using namespace std;

int isPrime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool isPrimeAdditivie(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return isPrime(sum);
}

class BST {
public:
  class Node {
  public:
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
  };
  void preOrder(Node *node) {
    if (!node) {
      return;
    }
    if (isPrimeAdditivie(node->data)) {
      cout << node->data << " ";
    }
    preOrder(node->left);
    preOrder(node->right);
  }

  void inOrder(Node *node) {
    if (!node) {
      return;
    }
    inOrder(node->left);
    if (isPrimeAdditivie(node->data)) {
      cout << node->data << " ";
    }
    inOrder(node->right);
  }

  void postOrder(Node *node) {
    if (!node) {
      return;
    }
    postOrder(node->left);
    postOrder(node->right);
    if (isPrimeAdditivie(node->data)) {
      cout << node->data << " ";
    }
  }

  Node *root;
  BST();

  void insert(Node *&node, int d);
  void deleteNode(Node *&node, int d);
  void traversalMenu();
  void display(Node *node, int spaces);
};

int main() {
  BST tree;
  int num, choice;
  while (1) {
    cout << "\n\n-----Binary Tree Operations-----\n[0]: Exit\n[1]: Insert node\n[2]: Delete node\n[3] Traversal Menu\nEnter choice: ";
    cin.clear();
    cin.ignore();
    cin >> choice;
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
      tree.traversalMenu();
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
  } else {
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

void BST::traversalMenu() {
  while (1) {
    int choice;
    cout << "\n\n-----Tree Traversal-----\n[0]: Back\n[1]: Preorder\n[2]: Inorder\n[3]: Postorder\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      system("cls");
      cout << "\nReturning to menu...";
      return;
    case 1:
      cout << "\nPreorder: ";
      preOrder(root);
      break;
    case 2:
      cout << "\nInorder: ";
      inOrder(root);
      break;
    case 3:
      cout << "\nPostorder: ";
      postOrder(root);
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