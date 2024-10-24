
// Assignment:
// 1. Mag provide og binary number
// 2. If ang decimal equivalent sa binary number is prime, mulugwa Ang mga functions sa stack og sa queue
// 3. After ana, Ang binary number nga provided kay ipa-agi sa push or sa pop
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int toDecimal(int num) {
  int sum = 0, pwr = 1;
  while (num > 0) {
    int rem = num % 10;
    sum += rem * pwr;
    pwr *= 2;
    num /= 10;
  }
  return sum;
}

class StackQueue {
public:
  size_t _size;
  int posStk;
  int posQ;
  vector<int> arr;

public:
  StackQueue() : posStk(-1), posQ(-1) {
    cout << "Enter size of Stack x Queue: ";
    cin >> this->_size;
  }

  bool isEmpty() { return arr.empty(); }
  bool isFull() { return arr.size() == _size; }
  void push(int n);
  void pop();
  void enqueue(int n);
  void dequeue();
  void printStkQ();
};

void StackQueue::push(int n) {
  if (isFull()) {
    cout << "Stack x Queue is full" << endl;
    return;
  }
  arr.insert(arr.begin(), n);
}

void StackQueue::pop() {
  if (isEmpty()) {
    cout << "Stack x Queue is empty" << endl;
    return;
  }
  arr.erase(arr.begin());
}

void StackQueue::enqueue(int n) {
  if (isFull()) {
    cout << "Stack x Queue is full" << endl;
    return;
  }
  arr.push_back(n);
}

void StackQueue::dequeue() {
  if (isEmpty()) {
    cout << "Stack x Queue is empty" << endl;
    return;
  }
  arr.erase(arr.begin());
}

void StackQueue::printStkQ() {
  cout << "\n\ntop of stack/front of queue" << endl;
  cout << "        |" << endl;
  cout << "        v" << endl;
  cout << "Output: ";
  for (int n : arr) {
    cout << n << " ";
  }
}

int main() {
  StackQueue list;
  int choice, bin;

  while (true) {
    cout << "\n\nEnter binary number: ";
    cin >> bin;
    int decimal = toDecimal(bin);
    if (!isPrime(decimal)) {
      cout << "The number is not prime." << endl;
      continue; // Ask for a new binary number
    }

    while (true) {
      cout << "\n\n-----Stack x Queue Operations-----\n[0]: Enter new binary number\n[1]: Push\n[2]: Pop\n[3]: Enqueue\n[4]: Dequeue\nEnter choice: ";
      cin.clear();
      cin >> choice;
      if (choice == 0) {
        break; // Exit inner loop to ask for a new binary number
      }
      switch (choice) {
      case 1:
        list.push(bin);
        break;
      case 2:
        if (!list.isEmpty()) {
          list.pop();
        } else {
          cout << "Stack is empty. Cannot pop." << endl;
        }
        break;
      case 3:
        list.enqueue(bin);
        break;
      case 4:
        if (!list.isEmpty()) {
          list.dequeue();
        } else {
          cout << "Queue is empty. Cannot dequeue." << endl;
        }
        break;
      default:
        cout << "Invalid choice" << endl;
      }
      list.printStkQ();
    }
  }

  return 0;
}