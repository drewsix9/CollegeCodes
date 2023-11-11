#include <iostream>
#include <string>
using namespace std;

class LinkedList {
  class Node {
  public:
    string data;
    Node *next;
    Node(string str) : data(str), next(nullptr) {}
    Node(string str, Node *n) : data(str), next(n) {}
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void insertEnd(string s) {
    if (!head) {
      head = new Node(s);
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node(s);
  }

  void deleteBegin() {
    if (!head) {
      return;
    }
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
  }

  Node *search(string s) {
    if (!head) {
      return nullptr;
    }
    Node *ptr = head;
    int count = 0;
    while (ptr && ptr->data != s) {
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

  void update_atNode(Node *n, string s) {
    Node *curr = head;
    while (curr != n) {
      curr = curr->next;
    }
    curr->data = s;
  }

  Node *before(Node *s) {
    Node *ptr = head;
    while (ptr && ptr->next && ptr->next != s) {
      ptr = ptr->next;
    }
    if (ptr->next != s) {
      return nullptr;
    }
    return ptr;
  }

  int size() {
    if (!head) {
      return 0;
    }
    int count = 0;
    Node *ptr = head;
    while (ptr) {
      ptr = ptr->next;
      count++;
    }
    return count;
  }

  void helperFunction(Node *&op, Node *&t, int &nT, int &nT2) {
    t = before(op);
    nT = stoi(t->data);
    nT2 = stoi(op->next->data);
    t = deleteAtNode(t);
    t = deleteAtNode(t);
  }

  int evaluate() {
    int res = 0;
    string p(1, '(');
    Node *par = search(p);
    if (par) { // if parenthesis exist
      Node *temp = par;
      temp = deleteAtNode(temp);
      res += stoi(temp->data);
      temp = deleteAtNode(temp);
      string oper = temp->data;
      if (oper == "*") {
        res *= stoi(temp->next->data);
      } else if (oper == "/") {
        res /= stoi(temp->next->data);
      } else if (oper == "+") {
        res += stoi(temp->next->data);
      } else if (oper == "-") {
        res -= stoi(temp->next->data);
      }
      for (int i = 0; i < 2; i++) {
        temp = deleteAtNode(temp);
      }
      string resString = to_string(res);
      update_atNode(temp, resString);
    }

    Node *temp;
    int numTemp, numTemp2;
    string m("*"), d("/"), a("+"), s("-");
    while (this->size() != 1) {
      Node *multi = search(m);
      if (multi) {
        helperFunction(multi, temp, numTemp, numTemp2);
        numTemp *= numTemp2;
        update_atNode(temp, to_string(numTemp));
      }
      Node *div = search(d);
      if (div) {
        helperFunction(div, temp, numTemp, numTemp2);
        numTemp /= numTemp2;
        update_atNode(temp, to_string(numTemp));
      }
      Node *add = search(a);
      if (add) {
        helperFunction(add, temp, numTemp, numTemp2);
        numTemp += numTemp2;
        update_atNode(temp, to_string(numTemp));
      }
      Node *sub = search(s);
      if (sub) {
        helperFunction(sub, temp, numTemp, numTemp2);
        numTemp -= numTemp2;
        update_atNode(temp, to_string(numTemp));
      }
    }
    return stoi(head->data);
  }
};

int main() {
  LinkedList li;
  string str;
  int j;
  cout << "\nEnter expression: ";
  cin >> str;
  for (int i = 0; i < str.size();) {
    if (isdigit(str[i])) {
      string res = "";
      while (isdigit(str[i])) {
        res += str[i];
        i++;
      }
      li.insertEnd(res);
    } else {
      li.insertEnd(str.substr(i, 1));
      i++;
    }
  }
  cout << "\nOutput: " << li.evaluate() << endl;
}