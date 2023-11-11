#include <iostream>
#include <vector>

// Automatically dequeue if the integer is a harshad number.
using namespace std;

class Queue {
  int MAX;
  vector<int> vec;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> MAX;
  }

  bool isFull() { return vec.size() == MAX; }
  bool isEmpty() { return vec.size() == 0; }
  int front() { return vec.front(); }

  void enqueue(int num) {
    vec.push_back(num);
    cout << "\n[INFO] Successfully enqueued";
  }

  void dequeue() {
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully dequeued";
  }

  void print() {
    cout << "\nQueue: ";
    for (int n : vec) {
      cout << n << " ";
    }
  }

  bool isHarshad(int num) {
    int temp = num, sum = 0;
    while (temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    return (num % sum == 0);
  }
};

int main() {
  Queue q;
  float num;
  int choice = -1;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Enqueue\n2 - Dequeue\nEnter choice: ";
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
      q.dequeue();
      break;
    default:
      cout << "\nWrong input!";
      break;
    }
    while (!q.isEmpty() && q.isHarshad(q.front())) {
      cout << "\n"
           << q.front() << " is dequeued";
      q.dequeue();
    }
    q.print();
    cout << "\n_______________________________________";
  }
}