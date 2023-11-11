#include <iostream>
using namespace std;

bool isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

class LinkedList {
  class Node {
  public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *n) : data(d), next(n) {}
  };

  Node *head;

public:
  LinkedList() {
    cout << "\nEnter starting number: ";
    int num;
    cin >> num;
    head = new Node(num);
  }

  void insert(int d) {
    if (!head) {
      head = new Node(d);
      return;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr->data < d && curr->next && curr->data != d) {
      prev = curr;
      curr = curr->next;
    }
    if (curr->data == d) {
      cout << "\nElement already exists in the list";
      return;
    }
    if (!prev && curr->data > d) { // At the beginning
      Node *nodeToInsert = new Node(d, curr);
      head = nodeToInsert;
      return;
    }
    if (!curr->next && curr->data < d) { // at the end
      curr->next = new Node(d);
      return;
    }
    prev->next = new Node(d, curr);
  }

  void print() {
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  void deleteComp() {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
      while (isPrime(curr->data) && curr->next) {
        prev = curr;
        curr = curr->next;
      }
      // delete
      if (!prev && !isPrime(curr->data)) {
        Node *delNode = curr;
        head = curr->next;
        delete delNode;
        curr = head;
      } else if (prev && !isPrime(curr->data)) {
        Node *delNode = curr;
        prev->next = delNode->next;
        delete delNode;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void deletePrime() {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
      while (!isPrime(curr->data) && curr->next) {
        prev = curr;
        curr = curr->next;
      }
      // delete
      if (!prev && isPrime(curr->data)) {
        Node *delNode = curr;
        head = curr->next;
        delete delNode;
        curr = head;
      } else if (prev && isPrime(curr->data)) {
        Node *delNode = curr;
        prev->next = delNode->next;
        delete delNode;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void reverse() {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    head = prev;
  }

  void sort() {
    for (auto i = head; i; i = i->next) {
      for (auto j = i->next; j; j = j->next) {
        if (i->data > j->data) {
          swap(i->data, j->data);
        }
      }
    }
  }
};

int main() {
  LinkedList li;
  int num, choice;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert\n[2] - Delete all non prime numbers\n[3] - Delete all prime numbers\n\[4] - Reverse list\n[5] - Sort\nEnter choice: ";
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
      li.deleteComp();
      break;
    case 3:
      li.deletePrime();
      break;
    case 4:
      li.reverse();
      break;
    case 5:
      li.sort();
      break;
    }
    li.print();
  }
}
