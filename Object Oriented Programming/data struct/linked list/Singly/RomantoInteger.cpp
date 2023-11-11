
#include <iostream>
#include <map>

using namespace std;

int HashTable(char c) {
  map<char, int> map{
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
  };
  return map[c];
}

class LinkedList {
  class Node {
  public:
    char data;
    Node *next;
    Node(char d) : data(d), next(nullptr) {}
    Node(char d, Node *n) : data(d), next(n) {}
  };

  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void insertEnd(char d) {
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

  int evaluate() {
    if (!head) {
      return 0;
    }
    int res = 0;
    Node *ptr = head;
    while (ptr) {
      char currC = ptr->data;
      if (!ptr->next) {
        res += HashTable(ptr->data);
        break;
      }
      char nextC = ptr->next->data;
      if (HashTable(currC) < HashTable(nextC)) {
        if (ptr->next->next && HashTable(nextC) <= HashTable(ptr->next->next->data)) {
          cout << "\nInput is invalid! ";
          return 0;
        }
        res -= HashTable(currC);
      } else {
        res += HashTable(currC);
      }
      ptr = ptr->next;
    }
    return res;
  }
};

int main() {

  LinkedList li;
  string str;
  cout << "Enter Roman Numeral: ";
  cin >> str;
  for (char c : str) {
    li.insertEnd(c);
  }
  cout << "\nOutput: " << li.evaluate();
}