#include <iostream>
#include <map>
using namespace std;

class Trie {
  class Node {
  public:
    map<char, Node *> children;
    bool endOfWord;
    Node() : endOfWord(false) {}
  };
  Node *root;

public:
  Trie() {
    root = new Node();
  }

  void insert(string word) {
    Node *curr = root;
    for (char c : word) {
      if (curr->children.find(c) == curr->children.end()) {
        curr->children[c] = new Node();
      }
      curr = curr->children[c];
    }
    curr->endOfWord = true;
  }

  bool search(string word) {
    Node *curr = root;
    for (char c : word) {
      if (curr->children.find(c) == curr->children.end()) {
        return false;
      }
      curr = curr->children[c];
    }
    return curr->endOfWord;
  }

  bool startsWith(string prefix) {
    Node *curr = root;
    for (char c : prefix) {
      if (curr->children.find(c) == curr->children.end()) {
        return false;
      }
      curr = curr->children[c];
    }
    return true;
  }
};

int main() {
  Trie trie;
  trie.insert("apple");
  cout << boolalpha << trie.search("apple") << endl;   // Output: 1 (true)
  cout << boolalpha << trie.search("app") << endl;     // Output: 0 (false)
  cout << boolalpha << trie.startsWith("app") << endl; // Output: 1 (true)
  trie.insert("app");
  cout << boolalpha << trie.search("app") << endl; // Output: 1 (true)

  return 0;
}