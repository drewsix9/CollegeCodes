#include <bits\stdc++.h>

using namespace std;

bool isVowel(char c) {
  string vowels = "aeiouAEIOU";
  int pos = vowels.find_first_of(c);
  return ((pos != string::npos) ? true : false);
}

template <typename T>
class LinkedList {
  class Node {
  public:
    T val;
    Node *next;
    Node(T d) : val(d), next(nullptr) {}
    Node(T d, Node *n) : val(d), next(n) {}
  };

public:
  Node *head;
  LinkedList() : head(nullptr) {}
  Node *insert(T d) {
    if (!head) {
      head = new Node(d);
      return head;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(d);
    return head;
  }

  Node *rearrangeVowels() {
    if (!head || !head->next) {
      return nullptr;
    }
    Node *dummy = new Node(0, head), *prev = dummy, *curr = head;
    while (curr && curr->next) {
      if (isVowel(curr->val)) {
        Node *tmpNext = curr->next, *tmpCurr = curr;
        prev->next = curr->next;
        helper(dummy, curr);
        prev = tmpCurr;
        curr = tmpNext;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy->next;
  }

  void helper(Node *&dummy, Node *&vowel) {
    Node *curr = dummy->next, *prv = dummy;
    while (curr && isVowel(curr->val) && curr->val <= vowel->val) {
      prv = curr;
      curr = curr->next;
    }
    if (curr) {
      vowel->next = curr;
      prv->next = vowel;
    }
  }

  void print(Node *h) {
    if (!h) {
      return;
    }
    Node *ptr = h;
    cout << "\nOutput: ";
    while (ptr) {
      cout << "'" << ptr->val << "'"
           << " -> ";
      ptr = ptr->next;
    }
    cout << "NULL";
  }
};

int main() {
  LinkedList<char> li;
  string str;
  cout << "Enter string: ";
  cin >> str;
  for (char c : str) {
    li.head = li.insert(c);
  }
  li.head = li.rearrangeVowels();
  li.print(li.head);
}