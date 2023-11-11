#include <initializer_list>
#include <iostream>

using namespace std;

class LinkedList {
public:
  class Node {
  public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *n) : data(d), next(n) {}
  };

  Node *head;
  LinkedList(std::initializer_list<int> list) {
    this->head = nullptr;
    for (auto item : list) {
      this->insertEnd(item);
    }
    cout << "\nInitialization list constructor successfully executed!";
  }

  LinkedList(Node *h) {
    this->head = nullptr;
    Node *ptr = h;
    while (ptr) {
      this->insertEnd(ptr->data);
      ptr = ptr->next;
    }
    cout << "\nCopy constructor successfully executed!";
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

pair<LinkedList, LinkedList> splitLinkedList(LinkedList li) {
  LinkedList::Node *slow = li.head, *fast = li.head, *prev = nullptr;
  while (fast && fast->next) {
    prev = slow;
    fast = fast->next->next;
    slow = slow->next;
  }
  LinkedList::Node *ptr = slow;
  prev->next = nullptr;
  return {LinkedList(li.head), LinkedList(ptr)};
}

void printPair(pair<LinkedList, LinkedList> LLpair) {
  cout << "\n1st half: ";
  LinkedList::Node *ptr = LLpair.first.head;
  while (ptr) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << "\n2nd half: ";
  ptr = LLpair.second.head;
  while (ptr) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
}

int main() {
  LinkedList li({1, 2, 3, 4, 5, 6});
  pair<LinkedList, LinkedList> pair = splitLinkedList(li);
  printPair(pair);
}