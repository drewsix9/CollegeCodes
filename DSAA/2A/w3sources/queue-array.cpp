#include <iostream>

using namespace std;

class Queue {
  int back, MAX;
  int arr[999];

public:
  Queue() : back(-1) {
    cout << "\nEnter Queueu size: ";
    cin >> MAX;
  }

  bool isEmpty() { return back == -1; }
  bool isFull() { return back == MAX - 1; }
  int printFront() { return arr[0]; }
  int printBack() { return arr[back]; }

  void enqueue(int num) {
    if (isFull()) {
      cout << "\nQueue is Full!";
      return;
    }
    back++;
    arr[back] = num;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "\nQueue is empty!";
      return;
    }

    for (int i = 1; i <= back; i++) {
      arr[i - 1] = arr[i];
    }
    back--;
  }

  void print() {
    cout << "\nQueue: ";
    for (int i = 0; i <= back; i++) {
      cout << arr[i] << " ";
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
    cout << "\n5 - Back";

    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\n[WARNING] Queue is Full!";
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
      if (q.isFull()) {
        cout << "\n[WARNING] Queue is Full!";
        break;
      }
      q.print();
      break;
    case 4:
      cout << "\nFront: " << q.printFront();
      break;
    case 5:
      cout << "\nBack: " << q.printBack();
      break;
    default:
      cout << "\n[WARNING] Wrong input!";
      break;
    }
    q.print();
    cout << "\n__________________________________";
  }
}
