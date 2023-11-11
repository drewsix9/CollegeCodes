#include <iostream>

using namespace std;

class LinkedList {
  class Node {
  public:
    int data;
    Node *next;
    // Constructors
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *n) : data(d), next(n) {}
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}
  void insertWhenEmpty(int d) {
    head = new Node(d);
  }

  void insertBegin(int d) {
    if (!head) {
      insertWhenEmpty(d);
      return;
    }
    auto newNode = new Node(d, head);
    head = newNode;
  }

  void insertEnd(int d) {
    if (!head) {
      insertWhenEmpty(d);
      return;
    }
    auto ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(d);
  }

  void insertAtIndex(int d, int pos) {
    if (pos < 0) {
      cout << "\nIndex out of range!";
      return;
    }
    if (pos == 0) {
      insertBegin(d);
      return;
    }
    auto ptr = head;
    // moving ptr to the index before the actual index to be inserted
    // there are two cases where the loop can exit, either it has reached pos-1 or ptr->next(node of pos) happens to be null
    for (int i = 0; i < pos - 1 && ptr->next; i++) {
      ptr = ptr->next;
    }
    // if the acutal index happens to be null
    if (!ptr->next) {
      cout << "\nIndex out of range!";
      return;
    }
    auto newNode = new Node(d, ptr->next);
    ptr->next = newNode;
  }

  void print() {
    if (!head) {
      cout << "\nLinked list is empty";
      return;
    }
    cout << "\nOutput: ";
    for (auto ptr = head; ptr; ptr = ptr->next) {
      cout << ptr->data << " -> ";
    }
    cout << "NULL";
  }

  void deleteAtBegin() {
    if (!head) {
      cout << "\nLinked List is already empty";
      return;
    }
    auto delNode = head;
    head = head->next;
    delete delNode;
  }

  void deleteAtEnd() {
    if (!head) {
      cout << "\nLinked List is already empty";
      return;
    }
    auto ptr = head;
    // moving ptr to the node before the last node
    while (ptr->next->next) {
      ptr = ptr->next;
    }
    delete ptr->next->next;
    ptr->next = nullptr;
  }

  void deleteAtIndex(int pos) {
    if (pos < 0) {
      cout << "\nIndex out of range!";
      return;
    }
    if (pos == 0) {
      deleteAtBegin();
      return;
    }
    auto ptr = head;
    // moving ptr to the index before the actual index to be deleted
    // there are two cases where the loop can exit, either it has reached pos-1 or ptr->next(node of pos)  happens to be null
    for (int i = 0; i < pos - 1 && ptr->next; i++) {
      ptr = ptr->next;
    }
    // if the node at given index happens to be null
    if (!ptr->next) {
      cout << "\nIndex out of range!";
      return;
    }
    auto delNode = ptr->next;
    ptr->next = ptr->next->next;
    delete delNode;
  }

  void reverse() {
    if (!head) {
      cout << "\nLinked list is empty";
      return;
    }
    auto curr = head;
    Node *prev = nullptr;

    while (curr) {
      auto temp = curr->next;
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

  void findMiddleNode() {
    if (!head) {
      cout << "\nLinked list is empty";
      return;
    }
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    cout << "\nMiddle element is: " << slow->data;
  }
};

int main() {
  LinkedList li;
  int num, choice, pos;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert at Beginning\n[2] - Insert at End\n[3] - Insert at index\n[4] - Delete at Beginning\n[5] - Delete at End\n[6] - Delete at Index\n[7] - Reverse\n[8] - Sort\n[9] - Middle Node\nEnter choice: ";
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
    case 3:
      cout << "\nEnter pos: ";
      cin >> pos;
      cout << "\nEnter num: ";
      cin >> num;
      li.insertAtIndex(num, pos);
      break;
    case 4:
      li.deleteAtBegin();
      break;
    case 5:
      li.deleteAtEnd();
      break;
    case 6:
      cout << "\nEnter pos: ";
      cin >> pos;
      li.deleteAtIndex(pos);
      break;
    case 7:
      li.reverse();
      break;
    case 8:
      li.sort();
      break;
    case 9:
      li.findMiddleNode();
      break;
    }
    li.print();
  }
}