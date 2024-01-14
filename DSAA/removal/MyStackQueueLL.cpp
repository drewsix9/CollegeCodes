#include "MyStackQueueLL.h"

template <typename T>
MyStackQueueLL<T>::MyStackQueueLL() {
  head = nullptr;
  tail = nullptr;
  cout << "Enter Stack/Queue size: ";
  cin >> _size;
}

template <typename T>
bool MyStackQueueLL<T>::isFull() {
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

template <typename T>
void MyStackQueueLL<T>::push(T n) {
  if (!head) {
    head = new Node(n);
    tail = head;
    return;
  }
  Node *newHead = new Node(n, head);
  head = newHead;
}

template <typename T>
void MyStackQueueLL<T>::pop() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

template <typename T>
void MyStackQueueLL<T>::enqueue(T n) {
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

template <typename T>
void MyStackQueueLL<T>::dequeue() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

template <typename T>
void MyStackQueueLL<T>::printLL() {
  if (!head) {
    cout << "\n[INFO] Linked list is empty" << endl;
    return;
  }
  cout << "\n\nTop of Stack/Front of Queue" << endl;
  cout << "          |" << endl;
  cout << "          v" << endl;
  cout << "\nOutput: ";
  Node *ptr = head;
  while (ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
}
