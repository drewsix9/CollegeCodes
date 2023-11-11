#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

bool isPrime(int num) {
  if (num == 2 || num == 3)
    return 1;
  if (num <= 1)
    return 0;
  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

template <typename T>
class Stack {
private:
  vector<T> v;
  int MAX;

public:
  Stack() {
    v = {};
    cout << "\nEnter stack size: ";
    cin >> MAX;
  }

  bool isFull() {
    return (v.size() == MAX);
  }

  void push(int d) {
    if (isFull()) {
      cout << "\n[WARNING] Stack is full. Cant perform push!";
      return;
    }
    v.push_back(d);
    cout << "\nSuccessfully pushed!";
  }

  void pop() {
    if (v.empty()) {
      cout << "\n[WARNING] Stack is empty. Nothing to pop!";
      return;
    }
    v.pop_back();
    cout << "\nSuccessfully popped!";
  }

  void printStack() {
    cout << "\nOutput: ";
    for (T n : v) {
      cout << n << " ";
    }
  }

  T &top() {
    return v.back();
  }
};

int main() {
  Stack<int> stk;
  set<int> unique;

  int num, choice = -1;
  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\n4 - Top";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is full. Cant perform push!";
        stk.printStack();
        break;
      }
      cout << "\nEnter input: ";
      cin >> num;
      if (unique.find(num) != unique.end()) {
        cout << "\n[WARNING] Cant stack an already stacked element!";
        stk.printStack();
        break;
      }
      unique.insert(num);
      stk.push(num);
      stk.printStack();
      break;
    case 2:
      if (!isPrime(stk.top())) {
        cout << "\n[WARNING] Cant perform pop. Top is not prime!";
        stk.printStack();
        break;
      }
      auto it = unique.find(stk.top());
      unique.erase(it);
      stk.pop();
      stk.printStack();
      break;
    case 3:
      stk.printStack();
      break;
    case 4:
      cout << "Top: " << stk.top();
      break;
    default:
      cout << "\n[WARNING] Wrong input!\n\n";
      break;
    }
  }
}