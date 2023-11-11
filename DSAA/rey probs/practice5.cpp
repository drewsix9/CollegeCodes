#include <iostream>
#include <set>
using namespace std;

bool isPrime(int num) {
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int getLesserComp(int prime) {
  while (prime > 0) {
    if (!isPrime(--prime)) {
      return prime;
    }
  }
  return 0;
}

int getGreaterPrime(int comp) {
  while (1) {
    if (isPrime(++comp)) {
      return comp;
    }
  }
  return 0;
}

class CircularLinkedList {
  class Node {
  public:
    pair<int, int> data; // <prime,comp>
    Node *next;
    Node() : data({}), next(nullptr) {}
  };
  Node *head;

  Node *newNodePrime(int n) {
    Node *res = new Node();
    res->data.first = n;
    res->data.second = getLesserComp(n);
    if (!head) {
      res->next = res;
    } else {
      res->next = head;
    }
    return res;
  }

  Node *newNodeComp(int n) {
    Node *res = new Node();
    res->data.first = getGreaterPrime(n);
    res->data.second = n;
    if (!head) {
      res->next = res;
    } else {
      res->next = head;
    }
    return res;
  }

public:
  CircularLinkedList() : head(nullptr) {}

  void insertNodePrime(int n) {
    if (!head) {
      head = newNodePrime(n);
      return;
    }
    Node *curr = head;
    while (curr->next != head) {
      curr = curr->next;
    }
    curr->next = newNodePrime(n);
  }

  void insertNodeComp(int n) {
    if (!head) {
      head = newNodeComp(n);
      return;
    }
    Node *curr = head;
    while (curr->next != head) {
      curr = curr->next;
    }
    curr->next = newNodeComp(n);
  }

  void print() {
    int pos;
    cout << "\nEnter pos(1-indexed): ";
    cin >> pos;
    pos--;
    Node *temp = head;
    while (pos > 0) {
      temp = temp->next;
      pos--;
    }
    Node *ptr = temp;
    cout << "\nOutput:\n";
    do {
      cout << "\nPrime: " << ptr->data.first << " Comp: " << ptr->data.second;
      ptr = ptr->next;
    } while (ptr != temp);
  }
};

int main() {
  CircularLinkedList cll;
  int num, choice;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert Node\n[2] - Print\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      if (isPrime(num)) {
        cll.insertNodePrime(num);
      } else {
        cll.insertNodeComp(num);
      }
      break;
    case 2:
      cll.print();
      break;
    }
  }
}