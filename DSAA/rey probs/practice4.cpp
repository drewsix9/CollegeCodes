#include <iostream>

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

int gcf(int x, int y) {
  int rem;
  while (1) {
    rem = x % y;
    if (rem == 0) {
      return y;
    }
    x = y;
    y = rem;
  }
}

using namespace std;

class LinkedList {
  class Node {
  public:
    int data;
    int gcf;
    Node *next;
    Node(int d) : data(d), gcf(0), next(nullptr) {}
    Node(int d, int _gcf, Node *n) : data(d), gcf(_gcf), next(n) {}
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}
  void insertBegin(int d) {
    if (!head) {
      head = new Node(d);
      return;
    }
    int temp = gcf(d, head->data);
    Node *newNode = new Node(d, temp, head);
    head = newNode;
  }

  void insertEnd(int d) {
    if (!head) {
      head = new Node(d);
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    Node *newNode = new Node(d);
    ptr->next = newNode;
    ptr->gcf = gcf(ptr->data, newNode->data);
  }

  void print() {
    cout << "\nList: ";
    Node *ptr = head;
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
    cout << "\nOutput:\n";
    ptr = head;
    while (ptr) {
      if (isPrime(ptr->gcf)) {
        cout << "\nData: " << ptr->data << " GCF: " << ptr->gcf;
      }
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList li;
  int num, choice;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert Beginning\n[2] - Insert End\nEnter Choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      li.insertBegin(num);
      break;
    case 2:
      cout << "\nEnter num: ";
      cin >> num;
      li.insertEnd(num);
      break;
    }
    li.print();
  }
}