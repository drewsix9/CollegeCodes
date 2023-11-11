#include <iostream>

using namespace std;

class LinkedList {
  class Node {
  public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *n) : data(d), next(n) {}
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  bool isEmpty() { return head == nullptr; }

  void push(int num) {
    if (isEmpty()) {
      head = new Node(num);
      return;
    }
    head = new Node(num, head);
  }

  void pop() {
    Node *del = head;
    head = head->next;
    delete del;
  }

  void print() {
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList stk;
  int num, choice = -1;
  while (1) {
    cout << "\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "\nExiting...";
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      stk.push(num);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.print();
      break;
    default:
      cout << "\n[WARNING] Wrong Input";
      break;
    }
    stk.print();
    cout << "\n__________________________________";
  }
}
