#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

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
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
  }

  void inOrder(Node *node) {
    if (!node) {
      return;
    }
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
  }

  void postOrder(Node *node) {
    if (!node) {
      return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
  }

  void breadthFirst() {
    queue<Node *> q;
    q.push(root);
    cout << "\nBreadth First: ";
    while (!q.empty()) {
      auto curr = q.front();
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
      cout << curr->data << " ";
      q.pop();
    }
  }

  void mapPrint(Node *node, map<Node *, Node *> map) {
    if (!node) {
      return;
    }
    mapPrint(node->left, map);
    cout << "node: " << node->data << " parent: ";
    cout << ((map[node]) ? map[node]->data : 0) << endl;
    mapPrint(node->right, map);
  }

  void mapping(Node *node, std::map<Node *, Node *> &nodeMap) {
    if (!node) {
      return;
    }
    if (node->left) {
      nodeMap[node->left] = node;
      mapping(node->left, nodeMap);
    }
    if (node->right) {
      nodeMap[node->right] = node;
      mapping(node->right, nodeMap);
    }
  }

  void kthSmallestHelper(Node *node, int &k, int &res) {
    if (!node) {
      return;
    }
    kthSmallestHelper(node->left, k, res);
    k--;
    if (k == 0) {
      res = node->data;
      return;
    }
    kthSmallestHelper(node->right, k, res);
  }

  Node *root;
  BST();

  void insert(Node *&node, int d);
  void deleteNode(Node *&node, int d);
  Node *search(Node *node, int d);
  void traversalMenu();
  void display(Node *node, int spaces);
  int size(Node *node);
  int minNode(Node *node);
  int height(Node *node);
  int countLeafNodes(Node *node);
  void printNodesAtKDistanceFromRoot(Node *node, int k);
  void printNodesAtKDistanceFromN(int n, int k);
  Node *invertTree(Node *&node);
  Node *lowestCommonAncestor(Node *node, int p, int q);
  int kthSmallest(Node *node, int k);
};

int main() {
  BST tree;
  int num, choice, k;
  while (1) {
    cout << "\n\n-----Binary Tree Operations-----\n[0]: Exit\n[1]: Insert node\n[2]: Delete node\n[3]: Search\n[4]: Tree Traversal\n[5]: Size\n[6]: Minimum value\n[7]: Height\n[8]: Count leaf nodes\n[9]: Print Nodes at K Distant from Root\n[10]: Print Nodes at K Distant from Node N\n[11]: Invert Tree\n[12]: Lowest Common Ancestor of two nodes\n[13]: Kth Smallest Element\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter node to insert: ";
      cin >> num;
      tree.insert(tree.root, num);
      break;
    case 2:
      cout << "\nEnter node to delete: ";
      cin >> num;
      tree.deleteNode(tree.root, num);
      break;
    case 3:
      cout << "\nEnter num to search: ";
      cin >> num;
      cout << "\nResult: ";
      cout << ((tree.search(tree.root, num)) ? "Does exist" : "Does NOT exist");
      break;
    case 4:
      tree.traversalMenu();
      break;
    case 5:
      cout << "\nTree size: " << tree.size(tree.root);
      break;
    case 6:
      cout << "\nMinimum node: " << tree.minNode(tree.root);
      break;
    case 7:
      cout << "\nHeight of tree: " << tree.height(tree.root);
      break;
    case 8:
      cout << "\nCount of leaf nodes: " << tree.countLeafNodes(tree.root);
      break;
    case 9:
      cout << "\nEnter distance from root: ";
      cin >> k;
      cout << "\nNodes of distance " << k << " from root: ";
      tree.printNodesAtKDistanceFromRoot(tree.root, k);
      break;
    case 10:
      cout << "\nEnter node to be the base point: ";
      cin >> num;
      cout << "Enter distance from node base point: ";
      cin >> k;
      tree.printNodesAtKDistanceFromN(num, k);
      break;
    case 11:
      tree.invertTree(tree.root);
      break;
    case 12:
      int x, y;
      cout << "\nEnter two nodes: ";
      cout << "\nEnter node 1: ";
      cin >> x;
      cout << "Enter node 2: ";
      cin >> y;
      cout << "\nLowest Common Ancestor of nodes " << x << " and " << y << ": " << tree.lowestCommonAncestor(tree.root, x, y)->data;
      break;
    case 13:
      int k;
      cout << "\nEnter Kth position (1-indexed): ";
      cin >> k;
      cout << "\nKth Smallest Element: " << tree.kthSmallest(tree.root, k);
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

BST::Node *BST::search(Node *node, int d) {
  if (!node) {
    return nullptr;
  }
  if (d == node->data) {
    return node;
  }
  if (d < node->data) {
    search(node->left, d);
  } else {
    search(node->right, d);
  }
}

void BST::traversalMenu() {
  while (1) {
    system("cls");
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
    case 4:
      breadthFirst();
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

int BST::size(Node *node) {
  if (!node) {
    return 0;
  }
  return 1 + size(node->left) + size(node->right);
}

int BST::minNode(Node *node) {
  if (!node) {
    return 0;
  }
  while (node->left) {
    node = node->left;
  }
  return node->data;
}

int BST::height(Node *node) {
  return (!node) ? 0 : 1 + max(height(node->left), height(node->right));
}

int BST::countLeafNodes(Node *node) {
  if (!node) {
    return 0;
  }
  if (!node->left && !node->right) {
    return 1;
  }
  return countLeafNodes(node->left) + countLeafNodes(node->right);
}

void BST::printNodesAtKDistanceFromRoot(Node *node, int k) {
  if (!node || k < 0) {
    return;
  }
  if (k == 0) {
    cout << node->data << " ";
    return;
  }
  printNodesAtKDistanceFromRoot(node->left, k - 1);
  printNodesAtKDistanceFromRoot(node->right, k - 1);
}

void BST::printNodesAtKDistanceFromN(int n, int k) {
  int temp = k;
  map<Node *, Node *> map; //[child, parent]
  mapping(root, map);
  Node *find = search(root, n);
  if (!find) {
    cout << "\nNode not found!";
    return;
  }
  queue<Node *> q;
  set<Node *> seen;
  q.push(find);
  seen.insert(find);
  while (k > 0) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node *curr = q.front();
      q.pop();
      if (curr) {
        // insert parent
        if (map[curr] && seen.find(map[curr]) == seen.end()) {
          q.push(map[curr]);
          seen.insert(map[curr]);
        }
        // insert left
        if (curr->left && seen.find(curr->left) == seen.end()) {
          q.push(curr->left);
          seen.insert(curr->left);
        }
        // insert right
        if (curr->right && seen.find(curr->right) == seen.end()) {
          q.push(curr->right);
          seen.insert(curr->right);
        }
      }
    }
    k--;
  }
  cout << "\nNodes of distance " << temp << " from Node " << n << ": ";
  while (!q.empty()) {
    cout << q.front()->data << " ";
    q.pop();
  }
}

BST::Node *BST::invertTree(Node *&node) {
  if (!node) {
    return nullptr;
  }
  Node *left = invertTree(node->left);
  Node *right = invertTree(node->right);
  node->left = right;
  node->right = left;
  return node;
}

BST::Node *BST::lowestCommonAncestor(Node *node, int p, int q) {
  if (p < node->data && q < node->data) {
    return lowestCommonAncestor(node->left, p, q);
  } else if (p > node->data && q > node->data) {
    return lowestCommonAncestor(node->right, p, q);
  } else {
    return node;
  }
}

int BST::kthSmallest(Node *node, int k) {
  int res;
  kthSmallestHelper(node, k, res);
  return res;
}