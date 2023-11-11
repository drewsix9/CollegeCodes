#include <iostream>
#include <set>
#include <vector>

// implement a stack function that deletes all occurences of user input n from the stack
// remove duplicates from a stack
using namespace std;

class Stack {
  int MAX;
  vector<int> v;

public:
  Stack() {
    cout << "\nEnter stack size: ";
    cin >> MAX;
  }

  bool isFull() { return v.size() == MAX; }
  bool isEmpty() { return v.size() == 0; }
  int &top() { return v.front(); }

  void push(int num) {
    v.insert(v.begin(), num);
    cout << "\nSuccessfully pushed";
  }

  void pop() {
    v.erase(v.begin());
    cout << "\nSuccessfully popped";
  }

  void removeNum(int num) {
    for (auto it = v.begin(); it != v.end(); it++) {
      if (*it == num) {
        v.erase(it);
        it--;
      }
    }
    cout << "\nRemoved " << num << " from the stack";
  }

  void removeDuplicates() {
    set<int> unique; // set na data struct kay mu keep ra ug unique elements (bawal duplicates)

    for (auto it = v.begin(); it != v.end(); it++) {
      if (unique.find(*it) != unique.end()) { // if *it is already inside set
        v.erase(it);
        it--;
      } else { // *it is not yet in set
        unique.insert(*it);
      }
    }
    cout << "\nRemoved deuplicates from stack";
  }

  void print() {
    cout << "\n      top";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nStack: ";
    for (int n : v) {
      cout << n << " ";
    }
  }
};

int main() {
  Stack stk;
  int num, choice;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Push\n2 - Pop\n3 - Print\n4 - Remove n from stack\n5 - Remove duplicates\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is FUll!";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      stk.push(num);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.print();
      break;
    case 4:
      cout << "\nEnter num: ";
      cin >> num;
      stk.removeNum(num);
      break;
    case 5:
      stk.removeDuplicates();
      break;
    }
    stk.print();
  }
}
