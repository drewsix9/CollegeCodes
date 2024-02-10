#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
private:
  class ListNode {
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int d) : data(d), next(nullptr) {}
    ListNode(int d, ListNode *n) : data(d), next(n) {}
  };

public:
  ListNode *head;
  LinkedList() : head(nullptr) {}
  void insert_front(int d) {
    if (!head) {
      head = new ListNode(d);
      cout << "\n[INFO] Successfully inserted at front!";

      return;
    }
    ListNode *newHead = new ListNode(d, head);
    head = newHead;
    cout << "\n[INFO] Successfully inserted at front!";
  }

  void insert_back(int d) {
    if (!head) {
      head = new ListNode(d);
      cout << "\n[INFO] Successfully inserted at back!";

      return;
    }
    ListNode *ptr = head;
    while (ptr->next) { // moving ptr to the end of list
      ptr = ptr->next;
    }
    ptr->next = new ListNode(d);
    cout << "\n[INFO] Successfully inserted at back!";
  }

  void insert_at(int d, int pos) {
    ListNode *prev = head;
    for (int i = 0; i < pos - 1; i++) { // moving ptr to the index before the position you want to insert
      prev = prev->next;
    }
    ListNode *newNode = new ListNode(d, prev->next);
    prev->next = newNode;
    cout << "\n[INFO] Successfully inserted at index" << pos;
  }

  void print() {
    cout << "\nOutput: ";
    ListNode *ptr = head;
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  void sortLL() {
    ListNode *a = head, *b;
    while (a) {
      for (b = a->next; b; b = b->next) {
        if (a->data > b->data) {
          int temp = a->data;
          a->data = b->data;
          b->data = temp;
        }
      }
      a = a->next;
    }
    cout << "\n[INFO] Successfully Sorted Linked List!";
  }

  void remove_at(int pos) {
    ListNode *prev = head;
    for (int i = 0; i < pos - 1; i++) { // // moving ptr to the index before the position you want to remove
      prev = prev->next;
    }
    ListNode *del = prev->next;
    prev->next = del->next;
    delete del;
    cout << "\n[INFO] Successfully deleted at index" << pos;
  }

  void update_at(int d, int pos) {
    ListNode *curr = head;
    for (int i = 0; i < pos; i++) {
      curr = curr->next;
    }
    curr->data = d;
    cout << "\n[INFO] Successfully Updated Node at Index " << pos;
  }

  int search(int d) {
    if (!head) {
      cout << "\n[WARNING] List is empty!";
      return -1;
    }
    ListNode *ptr = head;
    int count = 0;
    while (ptr && ptr->data != d) {
      ptr = ptr->next;
      count++;
    }
    if (!ptr) {
      return -1;
    }
    return count;
  }

  void rev() {
    if (!head) {
      cout << "\n[WARNING] List is empty!";
      return;
    }
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    head = prev;
    cout << "\n[INFO] Successfully Reversed Linked List";
  }

  int size() {
    if (!head) {
      return 0;
    }
    int count = 0;
    ListNode *ptr = head;
    while (ptr) {
      ptr = ptr->next;
      count++;
    }
    return count;
  }

  void rotateRight(int k) {
    if (k == 0 || !head || !head->next) {
      return;
    }
    int len = 0;
    ListNode *dummmy = new ListNode(0, head);
    ListNode *ptr = dummmy;
    while (ptr->next) {
      ptr = ptr->next;
      len++;
    }
    k = k % len;
    if (k == 0) {
      return;
    }
    ListNode *curr = head;
    for (int i = 0; i < len - k - 1; i++) {
      curr = curr->next;
    }
    ListNode *newHead = curr->next;
    curr->next = nullptr;
    ptr->next = this->head;
    this->head = newHead;
  }

  void oddEvenList() {
    if (!head || !head->next) {
      return;
    }
    ListNode *odd = head, *even = head->next, *temp = head->next;
    while (even && even->next) {
      odd->next = even->next;
      odd = even;
      even = even->next;
    }
    odd->next = temp;
    even->next = nullptr;
  }
};

int main() {
  LinkedList li;
  int num, choice = -1, pos;

  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Insert node at front";
    cout << "\n2 - Insert node at back";
    cout << "\n3 - Insert node at position";
    cout << "\n4 - Sort linked list";
    cout << "\n5 - Delete a Node";
    cout << "\n6 - Update Node Value";
    cout << "\n7 - Search Node";
    cout << "\n8 - Display Linked List";
    cout << "\n9 - Reverse Linked List";
    cout << "\n10 - Size";
    cout << "\n11 - Rotate to the right N times";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      li.insert_front(num);
      break;
    case 2:
      cout << "\nEnter num: ";
      cin >> num;
      li.insert_back(num);
      break;
    case 3:
      cout << "\nEnter num: ";
      cin >> num;
      cout << "\nEnter index to insert: ";
      cin >> pos;
      li.insert_at(num, pos);
      break;
    case 4:
      li.sortLL();
      break;
    case 5:
      cout << "\nEnter index to delete: ";
      cin >> pos;
      li.remove_at(pos);
      break;
    case 6:
      cout << "\nEnter num: ";
      cin >> num;
      cout << "\nEnter index to update: ";
      cin >> pos;
      li.update_at(num, pos);
      break;
    case 7:
      cout << "\nEnter num: ";
      cin >> num;
      cout << "\nFound num at index: " << li.search(num);
      break;
    case 8:
      li.print();
      break;
    case 9:
      li.rev();
      break;
    case 10:
      cout << "\nSize: " << li.size();
      break;
    case 11:
      cout << "\nEnter number of times to rotate: ";
      cin >> num;
      li.rotateRight(num);
      break;
    case 12:
      li.oddEvenList();
      break;
    default:
      cout << "\n[WARNING] Invalid input!";
      break;
    }
    li.print();
  }
  return 0;
}
