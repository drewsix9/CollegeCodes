#include <iostream>
#include <string>
// PEMDAS
using namespace std;

class LinkedList {
  class Node {
  public:
    char data;
    Node *next;
    Node(char c) : data(c), next(nullptr) {}
    Node(char c, Node *n) : data(c), next(n) {}
  };

  Node *head;

public:
  LinkedList() : head(nullptr) {}
  void insertEnd(char c) {
    if (!head) {
      head = new Node(c);
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(c);
  }

  void insertBegin(char c) {
    if (!head) {
      head = new Node(c);
      return;
    }
    Node *newNode = new Node(c, head);
    head = newNode;
  }

  void deleteBegin() {
    if (!head) {
      return;
    }
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
  }

  // float evaluate() {
  //   float res = 0.0;
  //   float curr = 0.0;
  //   Node *ptr = head;
  //   while (ptr) {
  //     switch (ptr->data) {
  //     case '*':
  //       res = curr * ptr->next->data;
  //       ptr =
  //     default:
  //       curr = ptr->data;
  //     }
  //     ptr = ptr->next;
  //   }
  // }

  void print() {
    if (!head) {
      return;
    }
    cout << "\nOutput: ";
    Node *ptr = head;
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList li;
  string input;
  cout << "\nEnter expression: ";
  cin >> input;

  float res = 0.0;
  auto par = input.find("(");
  if (par != string::npos) {
    li.insertEnd(input[par + 1]);
    li.insertEnd(input[par + 2]);
    li.insertEnd(input[par + 3]);
  }
  auto multi = input.find("*");
  if (multi != string::npos) {
    li.insertEnd(input[multi - 1]);
    li.insertEnd(input[multi]);
    li.insertEnd(input[multi + 1]);
  }
  auto div = input.find("/");
  if (div != string::npos) {
    li.insertEnd(input[div - 1]);
    li.insertEnd(input[div]);
    li.insertEnd(input[div + 1]);
  }
  auto add = input.find("+");
  if (add != string::npos) {
    li.insertEnd(input[add - 1]);
    li.insertEnd(input[add]);
    li.insertEnd(input[add + 1]);
  }
  auto sub = input.find("-");
  if (sub != string::npos) {
    li.insertEnd(input[sub - 1]);
    li.insertEnd(input[sub]);
    li.insertEnd(input[sub + 1]);
  }

  li.print();
  // cout << "\nOutput: " << li.evaluate();
}