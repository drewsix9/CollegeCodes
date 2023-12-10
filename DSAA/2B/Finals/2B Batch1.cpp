// print prme numbers and composite numbers in a linked list with their positions

#include <bits\stdc++.h>
#include <primecomp.h>

using namespace std;

class LinkedList {
  class Node {
  public:
    int val;
    Node *next;
    Node(int d) : val(d), next(nullptr) {}
    Node(int d, Node *n) : val(d), next(n) {}
  };

public:
  Node *head;
  LinkedList() : head(nullptr) {}
  void insert(int d) {
    if (!head) {
      head = new Node(d);
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(d);
  }

  void separate() {
    vector<pair<int, int>> prime; //[val,pos]
    vector<pair<int, int>> comp;
    Node *ptr = head;
    int n = 1;
    while (ptr) {
      if (isPrime(ptr->val)) {
        prime.push_back({ptr->val, n});
      } else {
        comp.push_back({ptr->val, n});
      }
      n++;
      ptr = ptr->next;
    }
    cout << "\nPrimes:\n";
    for (auto i = prime.begin(); i != prime.end(); i++) {
      cout << "Val: " << i->first << " Pos: " << i->second << endl;
    }
    cout << "\nComp:\n";
    for (auto i = comp.begin(); i != comp.end(); i++) {
      cout << "Val: " << i->first << " Pos: " << i->second << endl;
    }
  }

  void print() {
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList li;
  int num, choice;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert\n[2] - Separate\n[3] - Print\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      li.insert(num);
      break;
    case 2:
      li.separate();
      break;
    case 3:
      li.print();
      break;
    }
    li.print();
  }
}