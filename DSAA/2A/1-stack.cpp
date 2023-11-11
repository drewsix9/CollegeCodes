/*
input numbers, add to queue or stack, then auctomatically pop/dequeue if not binary. display inputs in decimal form
*/

#include <iostream>
#include <vector>

using namespace std;

class Stack {
  int MAX;
  vector<int> vec;

public:
  Stack() {
    cout << "\nEnter stack size: ";
    cin >> MAX;
  }

  bool isFull() {
    return vec.size() == MAX;
  }

  void push(int num) {
    vec.insert(vec.begin(), num);
    cout << "\n[INFO] Successfully pushed " << num;
    if (!isBinary(vec.front())) {
      pop();
      cout << "\n[INFO] Popped due to constraints";
    }
    print();
  }

  void pop() {
    if (vec.empty()) {
      cout << "\n[WARNING] Stack is empty";
      return;
    }
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully popped";
  }

  void print() {
    if (vec.empty()) {
      cout << "\n[WARNING] Stack is empty";
      return;
    }
    cout << "\n      top";
    cout << "\n       |";
    cout << "\n       V";
    cout << "\nStack: ";
    for (int n : vec) {
      cout << toDeci(n) << " ";
    }
  }

  bool isBinary(int num) {
    while (num > 0) {
      if ((num % 10) != 0 && (num % 10) != 1) {
        return 0;
      }
      num /= 10;
    }
    return 1;
  }

  int toDeci(int num) {
    int sum = 0, prod = 0, pow = 1;
    while (num > 0) {
      prod = (num % 10) * pow;
      pow *= 2;
      sum += prod;
      num /= 10;
    }
    return sum;
  }
};

int main() {
  Stack stk;
  int num, choice = -1;
  while (1) {
    cout << "\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "\nExiting...";
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is full";
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
    default:
      cout << "\n[WARNING] Wrong Input";
      break;
    }
    cout << "\n__________________________________";
  }
}
