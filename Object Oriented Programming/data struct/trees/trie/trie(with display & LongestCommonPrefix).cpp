#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Trie {
  class Node {
  public:
    char data;
    map<char, Node *> children;
    bool isWord;
    Node(char c) : data(c), isWord(false) {}
  };

public:
  Node *head;

  Trie() : head(new Node('\0')) {}

  void insert(string str) {
    Node *ptr = head;
    for (char c : str) {
      if (!ptr->children[c]) {
        ptr->children[c] = new Node(c);
      }
      ptr = ptr->children[c];
    }
    ptr->isWord = true;
  }

  Node *getNode(string str) {
    Node *ptr = head;
    for (char c : str) {
      if (!ptr->children[c]) {
        return nullptr;
      }
      ptr = ptr->children[c];
    }
    return ptr;
  }

  bool search(string str) {
    Node *ptr = getNode(str);
    return ptr && ptr->isWord;
  }

  bool startsWith(string pre) {
    Node *ptr = getNode(pre);
    return ptr;
  }

  void display(Node *n, int spaces) {
    if (!n)
      return;

    for (auto const &child : n->children) {
      for (int i = 0; i < spaces; i++)
        cout << " ";
      cout << child.first << endl;
      display(child.second, spaces + 2);
    }
  }

  Node *getNode(Node *parent, char c) {
    if (!parent->children[c]) {
      return nullptr;
    }
    return parent->children[c];
  }

  bool isValid(vector<string> strs, Node *ptr, Node *parent, int indx) {
    for (string str : strs) {
      if (ptr != getNode(parent, str[indx])) {
        return false;
      }
    }
    return true;
  }

  string LongestCommonPrefix(vector<string> strs) {
    for (string str : strs) {
      if (str.empty() || !search(str)) {
        return "";
      }
    }
    int indx = 0;
    string base = *(strs.begin());
    Node *ptr = getNode(head, base[0]);
    Node *parent = head;
    while (isValid(strs, ptr, parent, indx)) {
      parent = ptr;
      ptr = getNode(ptr, base[++indx]);
    }
    return base.substr(0, indx);
  }
};

int main() {

  Trie tree;
  tree.insert("undress");
  tree.insert("undo");
  tree.insert("uncover");

  tree.display(tree.head, 0);

  cout << "\nLongest Common Prefix: " << tree.LongestCommonPrefix({"undo", "uncover", "dress"});
}