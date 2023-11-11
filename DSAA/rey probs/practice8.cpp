#include <bits\stdc++.h>

using namespace std;

class LinkedList {
  class Node {
  public:
    string val;
    Node *next;
    Node(string s) : val(s), next(nullptr) {}
    Node(string s, Node *n) : val(s), next(n) {}
  };

public:
  Node *head;
  LinkedList() : head(nullptr) {}
  void insert(string s) {
    if (!head) {
      head = new Node(s);
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(s);
  }

  void print() {
    if (!head) {
      return;
    }
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << boolalpha << hasDuplicate(ptr->val) << " -> ";
      ptr = ptr->next;
    }
  }

  bool hasDuplicate(string str) {
    set<char> set;
    for (char c : str) {
      if (set.find(c) != set.end()) {
        return true;
      }
      set.insert(c);
    }
    return false;
  }
};

int main() {
  LinkedList li;
  string str = "", token;
  cout << "\nEnter string: ";
  getline(cin, str);
  stringstream ss(str);
  while (getline(ss, token, ' ')) {
    li.insert(token);
  }
  li.print();
}