#include <iostream>

using namespace std;

class LinkedList {
private:
  class Node {
  public:
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int d) : val(d), next(nullptr) {}
    Node(int d, Node *n) : val(d), next(n) {}
  };
  Node *head;
  Node *tail;

public:
  LinkedList() : head(nullptr), tail(nullptr) {}

  void insertBegin(int input) {
    if (!head) {
      head = new Node(input);
      cout << "\n[INFO] Successfully pushed_front!";
      return;
    }
    Node *temp = head;
    head = new Node(input);
    head->next = temp;
    cout << "\n[INFO] Successfully pushed_front!";
    return;
  }

  void insertBack(int input) {
    Node *newNode = new Node(input);
    if (!head) {
      head = newNode;
      tail = newNode;
      cout << "\n[INFO] Successfully pushed_back!";
      return;
    }
    tail->next = newNode;
    tail = newNode;
    cout << "\n[INFO] Successfully pushed_back!";
    return;
  }

  void print() {
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->val << " -> ";
      ptr = ptr->next;
    }
    cout << "NULL";
    return;
  }

  void deleteBegin() {
    if (!head) {
      cout << "\n[WARNING] Linked List is empty, nothing to pop";
      return;
    }
    Node *ptr = head;
    head = head->next;
    ptr = nullptr;
    delete ptr;
    cout << "\n[INFO] Successfully popped!";
    return;
  }

  void deleteBack() {
    if (!head) {
      cout << "\n[WARNING] Linked List is empty, nothing to pop";
      return;
    }
    Node *ptr = head;
    while (ptr->next != tail) {
      ptr = ptr->next;
    }
    tail = ptr;
    delete ptr->next;
    ptr->next = nullptr;
    cout << "\n[INFO] Successfully popped!";
    return;
  }

  int size() {
    int count = 0;
    if (!head) {
      return count;
    }
    Node *ptr = head;
    while (ptr) {
      count++;
      ptr = ptr->next;
    }
    return count;
  }

  void insertIndex(int d, int pos) {
    if (pos == 0) {
      insertBegin(d);
      return;
    }
    Node *prev = head;
    for (int i = 0; i < pos - 1 && prev->next; i++) {
      prev = prev->next;
    }
    if (!prev->next) {
      cout << "\nIndex out of bounds";
      return;
    }
    Node *newNode = new Node(d, prev->next);
    prev->next = newNode;
    cout << "\n[INFO] Successfully inserted!";
  }

  void deleteIndex(int pos) {
    if (pos == 0) {
      deleteBegin();
      return;
    }
    Node *prev = head;
    for (int i = 0; i < pos - 1 && prev->next; i++) {
      prev = prev->next;
    }
    if (!prev->next) {
      cout << "\nIndex out of bounds";
      return;
    }
    Node *delNode = prev->next;
    if (delNode == tail) {
      tail = prev;
    }
    prev->next = delNode->next;
    delete delNode;
    cout << "\n[INFO] Successfully deleted!";
  }

  void reverse() {
    if (!head || !head->next) {
      cout << "\n[WARNING] Reverse unsucessful!";
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
    swap(head, tail);
    cout << "\n[INFO] Successfully reversed!";
  }

  void sort() {
    if (!head || !tail) {
      cout << "\n[WARNING] Linked List is empty, nothing to sort";
      return;
    }
    for (auto i = head; i != nullptr; i = i->next) {
      for (auto j = i->next; j != nullptr; j = j->next) {
        if (i->val > j->val) {
          swap(i->val, j->val);
        }
      }
    }
    cout << "\n[INFO] Successfully sorted!";
  }

  void update(int num, int pos) {
    (*this)[pos] = num;
    cout << "\n[INFO] Successfully updated node " << pos;
  }

  bool search(int d) {
    if (!head || !tail) {
      cout << "\n[WARNING] Linked List is empty, nothing to sort";
      return 0;
    }
    Node *ptr = head;
    while (ptr) {
      if (ptr->val == d) {
        return 1;
      }
      ptr = ptr->next;
    }
    return 0;
  }

  int &operator[](int pos) {
    if (pos < 0) {
      throw runtime_error("Segmentation fault: Accessing null pointer");
    }
    if (pos == 0) {
      return head->val;
    } else {
      Node *ptr = head;
      for (int i = 0; i < pos && ptr; i++) {
        ptr = ptr->next;
      }
      if (!ptr) {
        throw runtime_error("Segmentation fault: Accessing null pointer");
      }
      return ptr->val;
    }
  }
};

int main() {
  int num, choice, indx;
  LinkedList li;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert Begin\n[2] - Insert Back\n[3] - Delete Begin\n[4] - Delete Back\n[5] - Size\n[6] - Insert at Index\n[7] - Delete at Index\n[8] - Reverse\n[9] - Sort\n[10] - Update\n[11] - Search\n[12] - Display specific node\nEnter choice: ";
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
      li.insertBack(num);
      break;
    case 3:
      li.deleteBegin();
      break;
    case 4:
      li.deleteBack();
      break;
    case 5:
      cout << "\nSize: " << li.size();
      break;
    case 6:
      cout << "\nEnter index:  ";
      cin >> indx;
      cout << "\nEnter num: ";
      cin >> num;
      li.insertIndex(num, indx);
      break;
    case 7:
      cout << "\nEnter index:  ";
      cin >> indx;
      li.deleteIndex(indx);
      break;
    case 8:
      li.reverse();
      break;
    case 9:
      li.sort();
      break;
    case 10:
      cout << "\nEnter index to update: ";
      cin >> indx;
      cout << "\nEnter num: ";
      cin >> num;
      li.update(num, indx);
      break;
    case 11:
      cout << "\nEnter num to search: ";
      cin >> num;
      cout << "\nSearch result: " << boolalpha << li.search(num);
    case 12:
      cout << "\nEnter index:  ";
      cin >> indx;
      cout << "\nOutput: " << li[indx];
      break;
    }
    li.print();
  }
}