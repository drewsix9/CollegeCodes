#include <cstring>
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
  string str;
  LinkedList() : head(nullptr) {
    cout << "\nEnter expression: ";
    cin >> str;
  }
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

  Node *search(char d) {
    if (!head) {
      cout << "\n[WARNING] List is empty!";
      return nullptr;
    }
    Node *ptr = head;
    int count = 0;
    while (ptr && ptr->data != d) {
      ptr = ptr->next;
      count++;
    }
    if (!ptr) {
      return nullptr;
    }
    return ptr;
  }

  Node *deleteAtNode(Node *n) {
    Node *tempN = n->next;
    if (n == head) {
      deleteBegin();
      return tempN;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != n) {
      prev = curr;
      curr = curr->next;
    }
    if (!curr) {
      cout << "\ndidnt find node";
      return nullptr;
    }
    Node *delNode = curr;
    prev->next = delNode->next;
    delete delNode;
    return prev->next;
  }

  bool isPar(char c) {
    return c == '(' || c == ')';
  }

  void update_at(Node *n, char c) {
    Node *curr = head;
    while (curr != n) {
      curr = curr->next;
    }
    curr->data = c;
    cout << "\n[INFO] Successfully Updated Node at Index ";
  }

  void update_atIndex(int pos, char d) {
    Node *curr = head;
    for (int i = 0; i < pos; i++) {
      curr = curr->next;
    }
    curr->data = d;
    cout << "\n[INFO] Successfully Updated Node at Index " << pos;
  }

  Node *remove_at(int pos) {
    Node *prev = head;
    for (int i = 0; i < pos - 1; i++) { // // moving ptr to the index before the position you want to remove
      prev = prev->next;
    }
    Node *del = prev->next;
    prev->next = del->next;
    delete del;
    cout << "\n[INFO] Successfully deleted at index" << pos;
    return prev->next;
  }

  char getVal(int pos) {
    if (!head) {
      cout << "\n[WARNING] List is empty!";
      return -1;
    }
    Node *ptr = head;
    while (pos > 0) {
      ptr = ptr->next;
      pos--;
    }
    return ptr->data;
  }

  float evaluate() {
    float res = 0.0;
    // PEMDAS
    Node *ptr = head;
    while (ptr) {
      auto par = search('(');
      if (par) { // if par exist
        Node *temp = par;
        int i = 3;
        while (i > 0) {
          char c = temp->data;
          if (isdigit(c) && i == 2) {
            res += (int)(c) - '0';
          } else if (!isPar(temp->data)) {
            switch (temp->data) {
            case '*':
              res *= ((int)(temp->next->data) - '0');
              break;
            case '/':
              res /= ((int)(temp->next->data) - '0');
              break;
            case '+':
              res += ((int)(temp->next->data) - '0');
              break;
            case '-':
              res -= ((int)(temp->next->data) - '0');
              break;
            }
          }
          temp = deleteAtNode(temp);
          i--;
        }
        temp = deleteAtNode(temp);
        update_at(temp, res);
        auto multi = str.find("*");
        if (multi != string::npos) {
          int prod = 0;
          prod += (int)str[multi - 1] - '0';
          prod *= (int)str[multi + 1] - '0';
          remove_at(multi - 1);
          remove_at(multi - 1);
          update_atIndex(multi - 1, prod + '0');
        }
        auto div = str.find("/");
        if (div != string::npos) {
          res += (int)str[div - 1] - '0';
          res /= (int)str[div + 1] - '0';
          remove_at(multi - 1);
          remove_at(multi - 1);
          remove_at(multi - 1);
        }
        auto add = str.find("+");
        if (add != string::npos) {
          res += (int)str[add - 1] - '0';
          res += (int)str[add + 1] - '0';
          remove_at(multi - 1);
          remove_at(multi - 1);
          remove_at(multi - 1);
        }
        auto sub = str.find("/");
        if (sub != string::npos) {
          res += (int)str[sub - 1] - '0';
          res -= (int)str[sub + 1] - '0';
          remove_at(multi - 1);
          remove_at(multi - 1);
          remove_at(multi - 1);
        }
      }
    }
    return res;
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
};

int main() {
  LinkedList li;
  for (char c : li.str) {
    li.insertEnd(c);
  }
  cout << "\nOutput: " << li.evaluate();
}