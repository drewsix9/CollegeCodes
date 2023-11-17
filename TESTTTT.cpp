#include <iostream>

using namespace std;

class AVLTree {
private:
  struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
  };

  int getHeight(Node *node) {
    if (node == nullptr)
      return 0;
    return node->height;
  }

  int getBalanceFactor(Node *node) {
    if (node == nullptr)
      return 0;
    return getHeight(node->left) - getHeight(node->right);
  }

  Node *rotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
  }

  Node *rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
  }

  Node *insertNode(Node *node, int key) {
    if (node == nullptr) {
      Node *newNode = new Node();
      newNode->key = key;
      newNode->left = nullptr;
      newNode->right = nullptr;
      newNode->height = 1;
      return newNode;
    }

    if (key < node->key)
      node->left = insertNode(node->left, key);
    else if (key > node->key)
      node->right = insertNode(node->right, key);
    else
      return node; // Duplicate keys not allowed

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
      if (key < node->left->key)
        return rotateRight(node);
      else if (key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
      }
    }

    if (balanceFactor < -1) {
      if (key > node->right->key)
        return rotateLeft(node);
      else if (key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
      }
    }

    return node;
  }

  void preOrderTraversal(Node *node) {
    if (node != nullptr) {
      std::cout << node->key << " ";
      preOrderTraversal(node->left);
      preOrderTraversal(node->right);
    }
  }

public:
  Node *root;

  AVLTree() {
    root = nullptr;
  }

  void insert(int key) {
    root = insertNode(root, key);
  }

  void printPreOrder() {
    preOrderTraversal(root);
    std::cout << std::endl;
  }

  void display(Node *n, int spaces) {
    if (!n) {
      return;
    }
    display(n->right, spaces + 10);
    cout << endl;
    for (int i = 10; i < spaces; i++) {
      cout << " ";
    }
    cout << n->key << endl;
    display(n->left, spaces + 10);
  }
};

int main() {
  AVLTree avlTree;

  avlTree.insert(40);
  avlTree.insert(20);
  avlTree.insert(10);
  avlTree.insert(25);
  avlTree.insert(30);
  avlTree.insert(22);
  avlTree.insert(50);

  std::cout << "Preorder traversal of the constructed AVL tree: ";
  avlTree.display(avlTree.root, 10);

  return 0;
}