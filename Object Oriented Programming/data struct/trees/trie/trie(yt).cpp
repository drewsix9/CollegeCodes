// https://www.youtube.com/watch?v=giiaIofn31A&t=611s
#include <iostream>

using namespace std;

class Trie {

  class Node {
  public:
    char data;
    Node *children[26];
    bool isWord;
    Node(char _c) : data(_c), isWord(false) {
      for (int i = 0; i <= 26; i++) {
        children[i] = nullptr;
      }
    }
  };

public:
  Node *head;
  Trie() {
    head = new Node('\0');
  }

  Node *getNode(string str) {
    Node *ptr = head;
    for (int i = 0; i < str.size(); i++) {
      char c = str[i];
      if (ptr->children[c - 'a']) {
        ptr = ptr->children[c - 'a'];
      } else {
        return nullptr;
      }
    }
    return ptr;
  }

  bool search(string str) {
    Node *res = getNode(str);
    return res && res->isWord;
  }

  bool startSwith(string str) {
    return getNode(str);
  }

  void insert(string str) {
    Node *ptr = head;
    for (int i = 0; i < str.size(); i++) {
      char c = str[i];
      if (!ptr->children[c - 'a']) {
        ptr->children[c - 'a'] = new Node(c);
      }
      ptr = ptr->children[c - 'a'];
    }
    ptr->isWord = true;
  }
};

int main() {
  Trie tree;
  string str;
  tree.insert("hello");
  tree.insert("hey");
  cout << "\nWord exist?: " << boolalpha << tree.search("hey");
  cout << "\nPrefix exist?: " << boolalpha << tree.startSwith("h");
}