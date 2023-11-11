#include <iostream>
#include <vector>

// automatically dequeue front if it is composite, and print its prime factors

using namespace std;

class Queue {
  int MAX;
  vector<int> vec;

public:
  Queue() {
    cout << "\nEnter Queue size: ";
    cin >> MAX;
  }

  bool isFull() {
    return MAX == vec.size();
  }

  bool isEmpty() {
    return vec.size() == 0;
  }

  void dequeue() {
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully dequeued";
  }

  void enqueue(int num) {
    vec.push_back(num);
    cout << "\n[INFO] Successfully enqueued";
  }

  bool isPrime(int num) {
    if (num == 2 || num == 3) {
      return 1;
    }
    if (num <= 1) {
      return 0;
    }
    for (int i = 2; i < num / 2 + 1; i++) {
      if (num % i == 0) {
        return 0;
      }
    }
    return 1;
  }

  int &front() {
    return vec.front();
  }

  void printPrimeF(int num) {
    cout << "\nPrime factors of " << num << " : ";
    for (int i = 2; i <= num; i++) {
      while (num % i == 0) {
        cout << i << " ";
        num /= i;
      }
    }
  }

  void printQueue() {
    cout << "\n     front";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nQueue: ";
    for (int n : vec) {
      cout << n << " ";
    }
  }
};

int main() {
  Queue q;
  int num, choice = -1;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Enqueue\n2 - Dequeue\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\n[INFO] Queue is full!";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      q.enqueue(num);
      break;
    case 2:
      q.dequeue();
      break;
    default:
      cout << "\n[WARNING] Wrong input!";
      break;
    }
    while (!q.isEmpty() && !q.isPrime(q.front())) {
      cout << "\n[INFO] " << q.front() << " is dequeued due to constraints";
      q.printPrimeF(q.front());
      q.dequeue();
    }
    q.printQueue();
    cout << "\n-----------------------------------------";
  }
}