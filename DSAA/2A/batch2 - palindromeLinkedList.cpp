// Kanang e link list Ang binary, then naay update, add last, delete last,
// Then e determine if palindrome ba ang binary ug prime ba Ang iyang decimal value
#include <iostream>
#include <math.h>

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
  LinkedList() : head(nullptr) {}

  // copy constructor
  LinkedList(const LinkedList &other) : head(nullptr) {
    if (other.head) {
      Node *otherPtr = other.head;
      Node *newPtr = new Node(otherPtr->data);
      head = newPtr;
      otherPtr = otherPtr->next;

      while (otherPtr) {
        newPtr->next = new Node(otherPtr->data);
        newPtr = newPtr->next;
        otherPtr = otherPtr->next;
      }
    }
  }

  void insertBegin(int d) {
    if (!head) {
      head = new Node(d);
      return;
    }
    Node *newNode = new Node(d, head);
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
    ptr->next = new Node(d);
  }

  void update(int pos, int d) {
    if (pos == 0) {
      head->data = d;
      return;
    }
    Node *ptr = head;
    while (pos > 0 && ptr) {
      ptr = ptr->next;
      --pos;
    }
    if (ptr) {
      ptr->data = d;
    }
  }

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

  int size() {
    Node *ptr = head;
    int count = 0;
    while (ptr) {
      count++;
      ptr = ptr->next;
    }
    return count;
  }

  bool isPrime() {
    Node *ptr = head;
    int deci = 0;
    while (ptr) {
      deci = deci * 10 + ptr->data;
      ptr = ptr->next;
    }

    int prod, sum = 0, pow = 1;
    while (deci > 0) {
      prod = deci % 10 * pow;
      pow *= 2;
      sum += prod;
      deci /= 10;
    }
    for (int i = 2; i < sum; i++) {
      if (sum % i == 0) {
        return 0;
      }
    }
    return 1;
  }
};

bool isPalindrome(const LinkedList list) {
  LinkedList copy(list);
  LinkedList::Node *slow, *fast;
  slow = fast = copy.head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  LinkedList::Node *prev = nullptr;
  while (slow) {
    LinkedList::Node *temp = slow->next;
    slow->next = prev;
    prev = slow;
    slow = temp;
  }

  LinkedList::Node *left = copy.head, *right = prev;
  while (right) {
    if (left->data != right->data) {
      return 0;
    }
    left = left->next;
    right = right->next;
  }
  return 1;
}

int main() {
  LinkedList li;
  string str;
  cout << "\nEnter binary: ";
  cin >> str;
  for (char c : str) {
    li.insertEnd(c - '0');
  }
  int num, choice, pos;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert Begin\n[2] - Insert End\n[3] - Update\n[4] - is Palindrome?\n[5] - is Prime?\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num(0/1): ";
      cin >> num;
      li.insertBegin(num);
      break;
    case 2:
      cout << "\nEnter num(0/1): ";
      cin >> num;
      li.insertEnd(num);
      break;
    case 3:
      cout << "\nEnter num(0/1): ";
      cin >> num;
      cout << "Enter pos: ";
      cin >> pos;
      li.update(pos, num);
      break;
    case 4:
      cout << "\nBinary is Palindrome?: " << boolalpha << isPalindrome(li);
      break;
    case 5:
      cout << "\nDecimal is Prime?: " << boolalpha << li.isPrime();
      break;
    }
    li.print();
  }
}