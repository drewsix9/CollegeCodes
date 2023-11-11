#include <iostream>

using namespace std;

class LinkedList {
private:
  class ListNode { // node declaration

  public:
    int data;
    ListNode *next; // node next declaration

    ListNode(int d) { // node setter function
      data = d;
      next = nullptr;
    }
    ListNode() {
      data = 0;
      next = nullptr;
    }
    ListNode(int d, ListNode *next) {
      data = d;
      next = next;
    }
  };

  ListNode *head; // head declaration

public:
  // constructor
  LinkedList() {
    head = nullptr;
  }

  void append(int input) {
    if (head == nullptr) {
      head = new ListNode(input);
      return;
    }

    ListNode *ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = new ListNode(input);
  }

  void display() {
    cout << "\nOutput: ";
    ListNode *ptr = head;
    while (ptr != nullptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList myList;
  int size, temp;

  cout << "Enter how many inputs: ";
  cin >> size;

  cout << "Enter inputs: ";
  for (auto i = 0; i < size; i++) {
    cin >> temp;
    myList.append(temp);
  }

  myList.display();

  return 0;
}