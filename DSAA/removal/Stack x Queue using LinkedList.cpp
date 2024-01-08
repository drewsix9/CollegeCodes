#include <iostream>

using namespace std;

class StackQueueLL {
public:
  class Node {
  public:
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *n) : val(val), next(n) {}
  };
  int _size;
  Node *head, *tail;
  StackQueueLL();
  bool isFull();
  bool isEmpty() { return head == nullptr; }
  void push(int n);
  void pop();
  void enqueue(int n);
  void dequeue();
  void printLL();
  Node *getFront() { return head; }
  Node *getTail() { return tail; }
};

int main() {
  StackQueueLL list;
  int choice, num;
  while (1) {
    cout << "\n\n-----Linked List Operations-----\n[0]: Exit\n[1]: Push\n[2]: Pop\n[3]: Enqueue\n[4]: Dequeue\nEnter choice: ";
    cin.clear();
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (list.isFull()) {
        cout << "[WARNING] Linked list is full" << endl;
        break;
      }
      cout << "Enter number to push: ";
      cin >> num;
      list.push(num);
      break;
    case 2:
      list.pop();
      break;
    case 3:
      if (list.isFull()) {
        cout << "[WARNING] Linked list is full" << endl;
        break;
      }
      cout << "Enter number to enqueue: ";
      cin >> num;
      list.enqueue(num);
      break;
    case 4:
      list.dequeue();
      break;
    default:
      cout << "Invalid choice" << endl;
    }
    list.printLL();
  }
}

StackQueueLL::StackQueueLL() {
  head = nullptr;
  tail = nullptr;
  cout << "Enter Stack/Queue size: ";
  cin >> _size;
}

bool StackQueueLL::isFull() {
  if (!head) {
    return false;
  }
  int n = 0;
  Node *ptr = head;
  while (ptr && n <= _size) {
    n++;
    ptr = ptr->next;
  }
  return n >= _size;
}

void StackQueueLL::push(int n) {
  if (!head) {
    head = new Node(n);
    tail = head;
    return;
  }
  Node *newHead = new Node(n, head);
  head = newHead;
}

void StackQueueLL::pop() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

void StackQueueLL::enqueue(int n) {
  if (!head) {
    head = new Node(n);
    tail = head;
    return;
  }
  Node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = new Node(n);
  tail = ptr->next;
}

void StackQueueLL::dequeue() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

void StackQueueLL::printLL() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  cout << "Output: ";
  Node *ptr = head;
  while (ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
}
