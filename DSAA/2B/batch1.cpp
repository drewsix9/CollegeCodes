#include <iostream>
#include <vector>

using namespace std;

class Queue {
  int MAX;
  vector<int> v;

public:
  Queue() {
    cout << "\nEnter max size: ";
    cin >> MAX;
  }

  bool isEmpty() { return v.empty(); }
  bool isFull() { return v.size() == MAX; }
  int &front() { return v.front(); }

  bool isPrime(int num) {
    if (num <= 1) {
      return 0;
    }
    for (int i = 2; i < num; i++) {
      if (num % i == 0) {
        return 0;
      }
    }
    return 1;
  }

  void enqueue(int n) {
    if (!isBinary(n) || !isPrime(BinToDeci(n))) {
      cout << "\nCannot enqueue " << n;
      return;
    }
    v.push_back(n);
    cout << "\nEnqueued " << n;
  }

  void dequeue() {
    v.erase(v.begin());
    cout << "\nDequeued";
  }

  void print() {
    cout << "\nOutput: ";
    for (int n : v) {
      cout << BinToDeci(n) << " ";
    }
  }

  int BinToDeci(int num) {
    int sum = 0, pow = 1, prod;
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
};

int main() {
  Queue q;
  int num, choice;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Enqueue\n2 - Dequeue\n3 - Print\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\nQueue is Full!";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      q.enqueue(num);
      break;
    case 2:
      if (q.isEmpty()) {
        cout << "\nQueue is empty";
        break;
      }
      q.dequeue();
      break;
    case 3:
      q.print();
      break;
    }
    q.print();
  }
}