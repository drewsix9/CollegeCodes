#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> v;
  int MAX;

public:
  Stack() {
    v = {};
    cout << "Enter stack size: ";
    cin >> MAX;
  }

  bool isEmpty() {
    return v.empty();
  }

  bool isFull() {
    return (MAX == v.size());
  }

  void push(int d) {
    v.push_back(d);
    cout << "\n[INFO] Successfully pushed!";
    print();
    return;
  }

  void pop() {
    if (isEmpty()) {
      cout << "\n[WARNING] Stack is Empty, Could not pop";
      return;
    }
    v.pop_back();
    cout << "\n[INFO] Successfully popped!";
    print();
    return;
  }

  void print() {
    if (isEmpty()) {
      cout << "\n[WARNING] Stack is Empty, Could not print";
      return;
    }
    cout << "\nOuput: ";
    for (int n : v) {
      cout << n << " ";
    }
    return;
  }

  void rev() {
    if (isEmpty()) {
      cout << "\n[WARNING] Stack is Empty, Could not reverse";
      return;
    }
    reverse(v.begin(), v.end());
    cout << "\n[INFO] Successfully Reversed!";
    print();
    return;
  }

  int &top() {
    return v.back();
  }
};

int main() {
  Stack stk;
  int num, choice = -1;

  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\n4 - Reverse";
    cout << "\n5 - Top";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is Full. Could not push";
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
      stk.rev();
      break;
    case 5:
      cout << "\nTop: " << stk.top();
      break;
    default:
      cout << "\n[WARNING] Wrong Input...\n";
    }
  }
}