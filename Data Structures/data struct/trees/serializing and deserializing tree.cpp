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