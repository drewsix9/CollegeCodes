#include <iostream>

using namespace std;

class DoublyLinkedList {
  class Node {
  public:
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int num) : data(num), prev(nullptr), next(nullptr) {}
    Node(int num, Node *p) : data(num), prev(p), next(nullptr) {}
    Node(int num, Node *p, Node *n) : data(num), prev(p), next(n) {}
  };
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}
  bool isEmpty() { return (head == nullptr); }

  void push_back(int d) {
    if (isEmpty()) {
      head = new Node(d);
      tail = head;
      cout << "\nPushed back " << d;
      return;
    }
    Node *newNode = new Node(d, tail);
    tail->next = newNode;
    tail = newNode;
    cout << "\nPushed back " << d;
  }

  void push_front(int d) {
    if (isEmpty()) {
      head = new Node(d);
      tail = head;
      cout << "\nPushed front " << d;
      return;
    }
    Node *newNode = new Node(d, nullptr, head);
    head->prev = newNode;
    head = newNode;
    cout << "\nPushed front " << d;
  }

  void printFromHead() {
    cout << "\nOutput(from head): ";
    if (isEmpty()) {
      return;
    }
    for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
      cout << ptr->data << " ";
    }
  }

  void printFromTail() {
    cout << "\nOutput(from tail): ";
    if (isEmpty()) {
      return;
    }
    for (auto ptr = tail; ptr != nullptr; ptr = ptr->prev) {
      cout << ptr->data << " ";
    }
  }

  void insertAtIndex(size_t indx, int num) {
    Node *ptr = head;
    for (int i = 0; i < indx - 1 && ptr; i++) {
      ptr = ptr->next;
    }
    if (!ptr) {
      cout << "Wrong index!";
      return;
    }
    Node *newNode = new Node(num, ptr, ptr->next);
    ptr->next->prev = newNode;
    ptr->next = newNode;
    cout << "\nInserted " << num << " at index " << indx;
  }

  void reverse() {
    // how to reverse a doubly linked list
  }
};

int main() {
  DoublyLinkedList dl;
  int num, choice;
  while (1) {
    cout << "\n\n[0] Exit\n[1] Push Back\n[2] Push Front\n[3] PrintFromHead\n[4] PrintFromTail\n[5] Insert at index\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      dl.push_back(num);
      break;
    case 2:
      cout << "\nEnter num: ";
      cin >> num;
      dl.push_front(num);
      break;
    case 3:
      dl.printFromHead();
      break;
    case 4:
      dl.printFromTail();
      break;
    case 5:
      size_t indx;
      cout << "\nEnter index: ";
      cin >> indx;
      cout << "\nEnter num: ";
      cin >> num;
      dl.insertAtIndex(indx, num);
      break;
    }
    dl.printFromHead();
  }
}