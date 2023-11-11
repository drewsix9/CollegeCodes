#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binToDeci(int num) {
  int sum = 0, prod = 0, pow = 1;
  while (num > 0) {
    prod = (num % 10) * pow;
    pow *= 2;
    sum += prod;
    num /= 10;
  }
  return sum;
}

bool isBinary(int num) {
  while (num > 0) {
    if (num % 10 > 1) {
      return 0;
    }
    num /= 10;
  }
  return 1;
}

bool isPrime(int num) {
  if (num <= 1)
    return 0;
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

class Queue {
public:
  vector<int> v;
  bool isEmpty() { return v.empty(); }
  void enqueue(int d) { v.push_back(d); }
  void dequeue() { v.erase(v.begin()); }

  void printBinaryQueue() {
    cout << "\n       front";
    cout << "\n         |";
    cout << "\n         v";
    cout << "\nBinary : ";
    for (int n : v) {
      cout << n << " ";
    }
  }

  void printDeciQueue() {
    cout << "\n       front";
    cout << "\n         |";
    cout << "\n         v";
    cout << "\nDecimal: ";
    for (int n : v) {
      cout << n << " ";
    }
  }

  void pinQueue(int num) {
    auto it = find(v.begin(), v.end(), num);
    if (it == v.end()) {
      cout << "\nInput number not found in Queue";
      return;
    }
    int temp = num;
    v.erase(it);
    this->enqueue(temp);
    cout << "\nSuccessfully pinned " << num;
  }
};

int main() {
  Queue binQ, deciQ;
  int num, choice, pin;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert num\n[2] - Pin a number\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      if (isBinary(num) && isPrime(binToDeci(num))) {
        binQ.enqueue(num);
      } else if (!isBinary(num) && !isPrime(num)) {
        deciQ.enqueue(num);
      } else {
        cout << "\nCannot enqueue " << num;
      }
      break;
    case 2:
      cout << "\nEnter num to pin: ";
      cin >> pin;
      if (isBinary(pin)) {
        binQ.pinQueue(pin);
      } else {
        deciQ.pinQueue(pin);
      }
      break;
    }
    binQ.printBinaryQueue();
    deciQ.printDeciQueue();
  }
}