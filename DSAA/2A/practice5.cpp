#include <iostream>
#include <vector>

// only accept octal form, display in decimal form

using namespace std;

class Stack {
  int MAX;
  vector<int> vec;

public:
  Stack() {
    cout << "\nEnter stack size: ";
    cin >> MAX;
  }

  bool isEmpty() { return vec.size() == 0; }
  bool isFull() { return vec.size() == MAX; }
  int top() { return vec.front(); }

  void pop() {
    if (isEmpty()) {
      cout << "\n[INFO] Stack is already empty";
      return;
    }
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully popped top";
  }

  void push(int num) {
    if (isOctal(num)) {
      vec.insert(vec.begin(), num);
      cout << "\n[INFO] Successfully pushed " << num;
    } else {
      cout << "\n[WARNING] " << num << " cant be pushed";
    }
  }

  void printDeci() {
    cout << "\n        top";
    cout << "\n         |";
    cout << "\n         v";
    cout << "\nStack:   ";
    for (int n : vec) {
      cout << n << " ";
    }
    cout << endl;
    cout << "Decimal: ";
    for (int n : vec) {
      cout << octalToDeci(n) << " ";
    }
  }

  int octalToDeci(int num) {
    int sum = 0, prod = 0, pow = 1;
    while (num > 0) {
      prod = (num % 10) * pow;
      pow *= 8;
      sum += prod;
      num /= 10;
    }
    return sum;
  }

  bool isOctal(int num) {
    while (num > 0) {
      if (!(num % 10 >= 0 && num % 10 <= 7)) {
        return 0;
      }
      num /= 10;
    }
    return 1;
  }
};

int main() {
  Stack stk;
  int num, choice;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Push\n2 - Pop\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
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
    default:
      cout << "\n[WARNING] Wrong input";
    }
    stk.printDeci();
  }
}