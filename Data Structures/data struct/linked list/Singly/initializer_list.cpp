#include <initializer_list>
#include <iostream>

using namespace std;

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
  LinkedList(std::initializer_list<int> list) {
    this->head = nullptr;
    for (auto item : list) {
      this->insertEnd(item);
    }
    cout << "\nInitialization list constructor successfully executed!";
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
    ptr->next = new Node(d);
  }

  void print() {
    if (head) {
      cout << "\nOutput: ";
      Node *ptr = head;
      while (ptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
      }
      cout << "NULL";
    }
  }
};

int main() {
  LinkedList li({1, 2, 3, 4, 5, 6});
  li.print();
}