#include <iostream>

using namespace std;

struct Node {
  Node *prev;
  int data;
  Node *next;
};

void printing(Node *head) {
  cout << "\nOutput: ";
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

void printingBackward(Node *tail) {
  cout << "\nOutput backwards: ";
  Node *temp = tail;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->prev;
  }
}

int main() {
  int temp;
  cout << "Enter inputs: ";
  cin >> temp;
  Node *head = new Node{nullptr, temp, nullptr};
  Node *ptr = head;

  while (cin >> temp && temp != 0) {
    ptr->next = new Node{ptr, temp, nullptr};
    ptr = ptr->next;
  }

  printing(head);
  printingBackward(ptr);

  return 0;
}