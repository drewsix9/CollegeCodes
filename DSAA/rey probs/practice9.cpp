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
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
  }

  void removeDuplicateString() {
    set<string> set;
    Node *dummy = new Node("", head), *prev = dummy, *curr = head;
    while (curr) {
      if (set.find(curr->val) != set.end()) {
        Node *delNode = curr;
        prev->next = curr->next;
        delete delNode;
        curr = prev->next;
      } else {
        set.insert(curr->val);
        prev = curr;
        curr = curr->next;
      }
    }
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
  li.removeDuplicateString();
  li.print();
}