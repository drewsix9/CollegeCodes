#include <iostream>

using namespace std;

int evaluate(int x, int y, string s) {
  if (s == "*") {
    return x * y;
  } else if (s == "/") {
    return x / y;
  } else if (s == "+") {
    return x + y;
  } else if (s == "-") {
    return x - y;
  }
  return 0;
}

class LinkedList {
public:
  class Node {
  public:
    string data;
    Node *next;
    Node(string s) : data(s), next(nullptr) {}
    Node(string s, Node *n) : data(s), next(n) {}
  };
  Node *head;

  LinkedList() : head(nullptr) {}

  Node *deleteNode(Node *n) {
    if (n == head) {
      Node *delNode = head;
      head = head->next;
      delete delNode;
      return head;
    }
    Node *prev = nullptr, *curr = head;
    while (curr != n) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == n) {
      Node *delNode = curr;
      prev->next = delNode->next;
      delete delNode;
    }
    return prev->next;
  }

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

  void print() {
    if (!head) {
      return;
    }
    Node *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  Node *search(string s) {
    if (!head) {
      return nullptr;
    }
    Node *ptr = head;
    while (ptr && ptr->data != s) {
      ptr = ptr->next;
    }
    if (ptr && ptr->data == s) {
      return ptr;
    }
    return nullptr;
  }
  Node *search(string s, Node *start, Node *end) {
    if (!head) {
      return nullptr;
    }
    Node *ptr = start;
    while (ptr && ptr != end && ptr->data != s) {
      ptr = ptr->next;
    }
    if (ptr && ptr != end && ptr->data == s) {
      return ptr;
    }
    return nullptr;
  }

  Node *searchBack(string s) {
    if (!head) {
      return nullptr;
    }
    Node *ptr = head;
    while (ptr->next->data != s && ptr->next) {
      ptr = ptr->next;
    }
    if (ptr) {
      return ptr;
    }
    return nullptr;
  }

  Node *getTail() {
    if (!head) {
      return nullptr;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    return ptr;
  }

  void helperofHelper(string s, Node *oper) {
    int x = stoi((searchBack(s))->data);
    int y = stoi(oper->next->data);
    int res = evaluate(x, y, oper->data);
    Node *temp = deleteNode(searchBack(s));
    temp = deleteNode(temp);
    temp->data = to_string(res);
  }

  void helper(Node *start, Node *end) {
    string m("*"), d("/"), a("+"), s("-");
    Node *multi, *div, *add, *sub;
    multi = search(m, start, end);
    div = search(d, start, end);
    add = search(a, start, end);
    sub = search(s, start, end);
    while (multi || div || add || sub) {
      if (multi) {
        helperofHelper(m, multi);
      } else if (div) {
        helperofHelper(d, div);
      } else if (add) {
        helperofHelper(a, add);
      } else if (sub) {
        helperofHelper(s, sub);
      }
      print();
      if (!head->next) {
        return;
      }
      multi = search(m, start, end);
      div = search(d, start, end);
      add = search(a, start, end);
      sub = search(s, start, end);
    };
  }

  void evaluateList() {
    Node *par = search("(");
    Node *close = search(")");
    // has parenthesis
    if (par) {
      Node *parEnd = searchBack(")");
      helper(par, close);
      // delete parentheses
      Node *temp = deleteNode(par);
      temp = deleteNode(search(")"));
    }
    helper(head, getTail());
  }
};

int main() {
  LinkedList li;
  string str;
  cout << "\nEnter expression: ";
  cin >> str;
  int i = 0;
  while (i < str.size()) {
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

  cout << endl;
  li.evaluateList();
  cout << "\n= " << li.head->data;

  return 0;
}