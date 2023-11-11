#include <iostream>
#include <vector>

// Automatically dequeue if the integer is a palindrome.
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
    print();
  }

  void dequeue() {
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully dequeued";
    print();
  }

  void print() {
    cout << "\nQueue: ";
    for (int n : vec) {
      cout << n << " ";
    }
  }

  bool isPalindrome(int num) {
    int div = 1;
    while (num >= div * 10) {
      div *= 10;
    }

    while (num > 0) {
      int left = num / div;
      int right = num % 10;

      if (left != right)
        return 0;

      num = (num % div) / 10;
      div /= 100;
    }
    return 1;
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
    while (!q.isEmpty() && q.isPalindrome(q.front())) {
      cout << "\n"
           << q.front() << " is dequeued";
      q.dequeue();
    }
    cout << "\n_______________________________________";
  }
}
