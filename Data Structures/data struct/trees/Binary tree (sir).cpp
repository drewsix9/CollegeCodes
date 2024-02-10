#include <cstdlib>
#include <cstring>
#include <iostream>
struct Node {
  long long data;
  Node *left;
  Node *right;
};
Node *root = NULL;
namespace BinaryTree {
class BST {
public:
  bool isEmpty() const { return root == NULL; }
  Node *insert(Node *, long long);
  Node *FindMin(Node *);
  Node *Delete(Node *, long long);
  bool Search(long long);
  int OddBinary(long long);
  void Preorder(Node *);
  void Inorder(Node *);
  void Postorder(Node *);
  void TreeTraversal();
  void display(Node *, int);
};
}; // namespace BinaryTree
Node *BinaryTree::BST::insert(Node *root, long long num) {
  if (root == NULL) {
    root = new Node();
    root->data = num;
    root->left = root->right = NULL;
  } else {
    if (num < root->data) {
      root->left = insert(root->left, num);
    } else {
      root->right = insert(root->right, num);
    }
  }
  return root;
}
bool BinaryTree::BST::Search(long long num) {
  bool found = false;
  if (isEmpty()) {
    std::cout << "\nTree is empty!\n";
    return false;
  }
  Node *current;
  Node *parent;
  current = root;
  while (current != NULL) {
    if (current->data == num) {
      found = true;
      break;
    } else {
      parent = current;
      if (num > current->data) {
        current = current->right;
      } else {
        current = current->left;
      }
    }
  }
  if (found == true) {
    return true;
  }
}
Node *BinaryTree::BST::FindMin(Node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}
Node *BinaryTree::BST::Delete(Node *root, long long num) {
  if (root == NULL) {
    return root;
  } else {
    if (num < root->data) {
      root->left = Delete(root->left, num);
    } else {
      if (num > root->data) {
        root->right = Delete(root->right, num);
      } else {
        if ((root->left == NULL) && (root->right == NULL)) {
          delete root;
          root = NULL;
        } else {
          if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
          } else {
            if (root->right == NULL) {
              Node *temp = root;
              root = root->left;
              delete temp;
            } else {
              Node *temp = FindMin(root->right);
              root->data = temp->data;
              root->right = Delete(root->right, temp->data);
            }
          }
        }
      }
    }
  }
  return root;
}
int BinaryTree::BST::OddBinary(long long num) {
  long long rem[100], error, count;
  count = 0;
  while (num) {
    rem[count] = num % 10;
    num = num / 10;
    count++;
  }
  error = 0;
  for (int i = 0; i < count; i++) {
    if ((rem[i] != 1) && (rem[i] != 0)) {
      error++;
    }
  }
  if (error == 0) {
    if (rem[0] == 1) {
      return 1;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}
void BinaryTree::BST::Preorder(Node *root) {
  if (root == NULL) {
    return;
  } else {
    std::cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
  }
}
void BinaryTree::BST::Inorder(Node *root) {
  if (root == NULL) {
    return;
  } else {
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
  }
}
void BinaryTree::BST::Postorder(Node *root) {
  if (root == NULL) {
    return;
  } else {
    Postorder(root->left);
    Postorder(root->right);
    std::cout << root->data << " ";
  }
}
void BinaryTree::BST::TreeTraversal() {
  system("cls");
  char choice;
  while (1) {
    std::cout << "-----Tree Traversal-----" << std::endl;
    std::cout << "[1]: Preorder" << std::endl;
    std::cout << "[2]: Inorder" << std::endl;
    std::cout << "[3]: Postorder" << std::endl;
    std::cout << "[4]: Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    switch (choice) {
    case '1':
      std::cout << "\nPreorder: ";
      Preorder(root);
      std::cout << std::endl
                << std::endl;
      break;
    case '2':
      std::cout << "\nInorder: ";
      Inorder(root);
      std::cout << std::endl
                << std::endl;
      break;
    case '3':
      std::cout << "\nPostorder: ";
      Postorder(root);
      std::cout << std::endl
                << std::endl;
      break;
    case '4':
      system("cls");
      std::cout << "Terminating Program......";
      exit(0);
      break;
    default:
      std::cout << "\nWrong Choice!\n\n";
      break;
    }
  }
}
void BinaryTree::BST::display(Node *ptr, int level) {
  if (ptr != NULL) {
    display(ptr->right, level + 1);
    std::cout << std::endl;
    if (ptr == root) {
      std::cout << "Root-> ";
    } else {
      for (int i = 0; i < level; i++) {
        std::cout << " ";
      }
    }
    std::cout << ptr->data;
    display(ptr->left, level + 1);
  }
}
int main() {
  BinaryTree::BST bst;
  char choice;
  long long num;
  std::cout << "---Creating Root Node---" << std::endl;
  bool done = false;
  while (!done) {
    std::cout << "Enter binary number: ";
    std::cin >> num;
    if (bst.OddBinary(num) == 1) {
      system("cls");
      root = bst.insert(root, num);
      bst.display(root, 1);
      done = true;
    } else {
      std::cout << "\nERROR 404: Odd Binary number not found!\n\n";
    }
  }
  std::cout << std::endl;
  while (1) {
    std::cout << "\n---Binary Tree Operations---\n";
    std::cout << "[1]: Insert node\n";
    std::cout << "[2]: Delete node\n";
    std::cout << "[3]: Search\n";
    std::cout << "[4]: Tree Traversal\n";
    std::cout << "[5]: Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    switch (choice) {
    case '1':
      std::cout << "\nEnter binary number: ";
      std::cin >> num;
      if (bst.OddBinary(num) == 1) {
        if (bst.Search(num)) {
          std::cout << "\nElement already inserted!\n";
        } else {
          if (num != 0) {
            std::cout << std::endl;
            root = bst.insert(root, num);
            bst.display(root, 1);
            std::cout << std::endl
                      << std::endl;
          } else {
            std::cout << "\nNumber is not an odd binary number !\n ";
          }
        }
      } else {
        std::cout << "\nNumber is not an odd binary number!\n";
      }
      break;
    case '2': {
      std::cout << "\nEnter a number: ";
      std::cin >> num;
      if (bst.Search(num)) {
        std::cout << std::endl;
        root = bst.Delete(root, num);
        bst.display(root, 1);
        std::cout << "\n\n\nElement deleted!\n";
      } else {
        std::cout << "\nElement not found!\n";
      }
      break;
    }
    case '3':
      std::cout << "\nFind an element: ";
      std::cin >> num;
      if (bst.Search(num)) {
        std::cout << "\nElement found!\n";
      } else {
        std::cout << "\nElement not found!\n";
      }
      break;
    case '4':
      bst.TreeTraversal();
      break;
    case '5':
      system("cls");
      std::cout << "Terminating Program......";
      exit(0);
      break;
    default:
      std::cout << "\nWrong Choice!\n";
      break;
    }
  }
  return 0;
}