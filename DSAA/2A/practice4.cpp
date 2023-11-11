#include <iostream>
#include <vector>

// auto dequeue if front is not a whole number

using namespace std;

class Queue {
  int MAX;
  vector<float> vec;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> MAX;
  }

  bool isFull() {
    return vec.size() == MAX;
  }

  void dequeue() {
    vec.erase(vec.begin());
    cout << "\nDequeued!";
  }

  void enqueue(float num) {
    vec.push_back(num);
    cout << "\nEnqueued!";
  }

  void print() {
    cout << "\n     front";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nQueue: ";
    for (float n : vec) {
      cout << n << " ";
    }
  }

  bool isNotWhole(float num) {
    return (num - (int)num);
  }

  bool isEmpty() {
    return vec.size() == 0;
  }

  float front() {
    return vec.front();
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
    while (!q.isEmpty() && q.isNotWhole(q.front())) {
      cout << "\n"
           << q.front() << " is dequeued";
      q.dequeue();
    }
    q.print();
  }
}