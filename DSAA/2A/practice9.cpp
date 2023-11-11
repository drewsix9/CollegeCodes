// automatically dequeue if:
// If the front element is a prime number, simply dequeue it.
// If the front element is composite, print its prime factors and dequeue it.
// If the front element is a power of 2, enqueue its square root and dequeue it.
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Queue {
  int MAX;
  vector<int> v;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> MAX;
  }

  bool isEmpty() { return v.empty(); }
  bool isFull() { return v.size() == MAX; }
  int &front() { return v.front(); };

  void enqueue(int n) {
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
      cout << n << " ";
    }
  }

  bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }

  void printPrimeFactors(int num) {
    cout << "\nPrime factors of " << num << " are: ";
    for (int i = 2; i <= num; i++) {
      while (num % i == 0) {
        cout << i << " ";
        num /= i;
      }
    }
  }

  bool isPowerOfTwo(int n) {
    int i = 2;
    while (i < n) {
      i *= 2;
    }
    return (i == n) ? 1 : 0;
  }
};

int main() {
  Queue q;
  int num, choice;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Enqueue\n2 - Dequeue\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\nQueue is full!";
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
    }
    while (q.isPrime(q.front()) && !q.isEmpty()) {
      q.dequeue();
      cout << "\nDequeued because front is a prime number.";
    }
    // while (!q.isPrime(q.front()) && !q.isEmpty()) {
    //   q.printPrimeFactors(q.front());
    //   q.dequeue();
    //   cout << "\nDequeued because front is a composite number.";
    // }
    while (q.isPowerOfTwo(q.front()) && !q.isEmpty()) { 
      q.enqueue(sqrt(q.front()));
      cout << "\nDequeued because " << q.front() << " is power of 2. ";
      q.dequeue();
    }
    q.print();
  }
}
