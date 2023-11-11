#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Queue {
private:
  list<int> l;

public:
  bool isEmpty() {
    return (l.empty());
  }

  void enqueue(int d) {
    l.push_back(d);
    cout << "\n[INFO] Successfully added to queue!";
    print();
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "\n[INFO] Queue is Empty. Nothing to pop.";
      return;
    }
    l.pop_front();
    cout << "\n[INFO] Successfully removed from queue!";
    print();
  }

  void print() {
    if (isEmpty()) {
      cout << "\n[INFO] Queue is Empty.";
      return;
    }
    cout << "\nOutput: ";
    for (int i : l) {
      cout << i << " ";
    }
  }

  void front() {
    if (isEmpty()) {
      cout << "\n[INFO] Queue is Empty.";
      return;
    }
    cout << "\nFront: " << l.front();
  }

  void clear() {
    if (isEmpty()) {
      cout << "\n[INFO] Queue is Empty.";
      return;
    }
    l.clear();
    cout << "\n[INFO] Queue Successfully Cleared";
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
      q.front();
      break;
    default:
      cout << "\nInvalid Input...\n\n";
      break;
    }
  }
}
