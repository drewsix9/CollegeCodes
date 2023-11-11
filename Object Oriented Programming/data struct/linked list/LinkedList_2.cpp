#include <iostream>

using namespace std;

class LinkedList {
private:
  struct Node {
    int data;
    Node *next = nullptr;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *next) : data(d), next(next) {}
  };
  Node *head = nullptr;

public:
  LinkedList() : head(nullptr) {}

  Node *getHead() {
    return head;
  }

  void append(int input) {
    if (head == nullptr) {
      head = new Node(input);
      return;
    }

    Node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new Node(input);
  }

  void display() {
    cout << "\nOutput: ";
    Node *temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

  void reverseList() {
    cout << "\nReversing List...";
    if (head == nullptr || head->next == nullptr) {
      return;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    cout << "\nList Successfully Reversed!";
    head = prev;
    return;
  }
};

int main() {
  LinkedList list1;
  int size, temp;
  cout << "Enter size: ";
  cin >> size;
  cout << "Enter inputs: ";
  for (int i = 0; i < size; i++) {
    cin >> temp;
    list1.append(temp);
  }

  list1.display();

  list1.reverseList();

  list1.display();
}