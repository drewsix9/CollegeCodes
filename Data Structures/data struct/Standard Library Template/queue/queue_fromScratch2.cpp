#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
  vector<int> v;
  int MAX;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> MAX;
  }
  bool isEmpty() {
    return v.empty();
  }

  bool isFull() {
    return v.size() == MAX;
  }

  void enqueue(int value) {
    v.push_back(value);
    cout << "\n[INFO] Enqueue Successful!";
    print();
  }
  void dequeue() {
    if (isEmpty()) {
      cout << "\n[WARNING] Queue is Empty, Cant Perform Dequeue";
      return;
    }
    v.erase(v.begin());
    cout << "\n[INFO] Dequeue Successful!";
    print();
  }

  int &front() {
    return v.front();
  }

  void print() {
    if (isEmpty()) {
      cout << "\n[WARNING] Queue is Empty, Cant Perform Print";
      return;
    }
    cout << "\nOutput: ";
    for (int item : v) {
      cout << item << " ";
    }
  }
};

int main() {
  Queue q;
  int num, choice = -1;

  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Enqueue";
    cout << "\n2 - Dequeue";
    cout << "\n3 - Print";
    cout << "\n4 - Front";
    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\n[INFO] Queue is Full!";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      q.enqueue(num);
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      q.print();
      break;
    case 4:
      cout << "\nFront: " << q.front();
      break;
    default:
      cout << "\nInvalid Input...\n\n";
      break;
    }
  }
}