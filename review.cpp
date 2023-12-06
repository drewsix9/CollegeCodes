

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
private:
  Node *root;

public:
  BinaryTree() {
    root = nullptr;
  }

  // ... existing code ...

  string serialize() {
    stringstream ss;
    serializeRecursive(root, ss);
    return ss.str();
  }

  void serializeRecursive(Node *current, stringstream &ss) {
    if (current == nullptr) {
      ss << "null ";
      return;
    }

    ss << current->data << " ";
    serializeRecursive(current->left, ss);
    serializeRecursive(current->right, ss);
  }

  Node *deserialize(string data) {
    vector<string> nodes;
    stringstream ss(data);
    string node;

    while (ss >> node) {
      nodes.push_back(node);
    }

    int index = 0;
    return deserializeRecursive(nodes, index);
  }

  Node *deserializeRecursive(const vector<string> &nodes, int &index) {
    if (index >= nodes.size() || nodes[index] == "null") {
      return nullptr;
    }

    int value = stoi(nodes[index]);
    Node *newNode = new Node(value);

    newNode->left = deserializeRecursive(nodes, ++index);
    newNode->right = deserializeRecursive(nodes, ++index);

    return newNode;
  }

  Node *findMinNode(Node *current) {
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }
};

int main() {
  BinaryTree tree;

  tree.insert(50);
  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(70);
  tree.insert(60);
  tree.insert(80);

  std::cout << "Inorder Traversal: ";
  tree.inorderTraversal();
  std::cout << std::endl;

  std::cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << std::endl;
  std::cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << std::endl;

  tree.deleteNode(40);
  std::cout << "Inorder Traversal after deleting 40: ";
  tree.inorderTraversal();
  std::cout << std::endl;

  return 0;
}
