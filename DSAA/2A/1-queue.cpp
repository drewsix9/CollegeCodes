/*
input numbers, add to queue or stack, then auctomatically pop/dequeue if not binary. display inputs in decimal form

*/

#include <iostream>
#include <vector>

using namespace std;

class Queue {
  int size;
  vector<int> vec;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> this->size;
  }

  bool isFull() {
    return size == vec.size();
  }

  void pop() {
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully popped";
    print();
  }

  void push(int num) {
    vec.push_back(num);
    cout << "\n[INFO] Successfully pushed " << num;
    print();
  }

  void print() {
    cout << "\n     front";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nQueue: ";
    for (int n : vec) {
      cout << toDeci(n) << " ";
    }
  }

  bool isBinary(int num) {
    while (num > 0) {
      if ((num % 10) != 0 && (num % 10) != 1) {
        return 0;
      }
      num /= 10;
    }
    return 1;
  }

  int toDeci(int num) {
    int sum = 0, prod = 0, pow = 1;
    while (num > 0) {
      prod = (num % 10) * pow;
      pow *= 2;
      sum += prod;
      num /= 10;
    }
    return sum;
  }

  int &front() {
    return vec.front();
  }
};

int main() {
  Queue q;
  int num, choice = -1;
  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
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
      q.push(num);
      break;
    case 2:
      q.pop();
      break;
    case 3:
      q.print();
      break;
    default:
      cout << "\n[WARNING] Wrong input!";
      break;
    }
    while (!q.isBinary(q.front())) {
      q.pop();
      cout << "\n[WARNING] Top has been popped due to constraints";
      q.print();
    }
    cout << "\n__________________________________";
  }
}
